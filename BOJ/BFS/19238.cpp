#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
#define tup tuple<int, int, int>
#define pii pair<int, int>

int N, M, fuel, pivot, taxi_x, taxi_y;

bool chk[21][21];
int board[21][21];
int arr[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

vector <pii> v;

bool chk_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!(!board[i][j] || board[i][j] == 1)) return false;
        }
    }
    return true;
}

void find_dest(int x, int y, int idx){
    memset(chk, 0, sizeof(chk));
    queue <tup> q;
    int dest_x = v[idx].first;
    int dest_y = v[idx].second;
    if(x == dest_x && y == dest_y) {taxi_x = x, taxi_y = y; return;}
    q.push({x, y, 0});
    while(!q.empty()){
        tup tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = get<0>(tmp) + arr[i][0];
            int dy = get<1>(tmp) + arr[i][1];
            int tmp_dist = get<2>(tmp) + 1;
            if(board[dx][dy] == 1 || dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy]) continue;
            chk[dx][dy] = true;
            if(dx == dest_x && dy == dest_y){
                fuel -= tmp_dist;
                if(fuel < 0) return;
                fuel += tmp_dist * 2;
                taxi_x = dx, taxi_y = dy;
                return;
            }
            q.push({dx, dy, tmp_dist});
        }
    }
    fuel = -1;
}

void foo(){
    memset(chk, 0, sizeof(chk));
    queue <tup> q;
    pii min; min.first = -1, min.second = -1;
    int dist = 0x6f6f6f6, idx;
    
    q.push({taxi_x, taxi_y, 0});
    if(board[taxi_x][taxi_y] >= 2) {
        int dx = taxi_x, dy = taxi_y;
        find_dest(taxi_x, taxi_y, board[taxi_x][taxi_y]), board[dx][dy] = 0; return;
        }
    while(!q.empty()){
        tup tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = get<0>(tmp) + arr[i][0];
            int dy = get<1>(tmp) + arr[i][1];
            int tmp_dist = get<2>(tmp) + 1;
            if(board[dx][dy] == 1 || dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy]) continue;
            chk[dx][dy] = true;
            if(board[dx][dy] >= 2 && tmp_dist <= dist){
                if(tmp_dist < dist) min.first = dx, min.second = dy, idx = board[dx][dy], dist = tmp_dist;
                else{
                    if(min.first < dx) ;
                    else if(min.first == dx){
                        if(min.second < dy) ;
                        else min.first = dx, min.second = dy, idx = board[dx][dy], dist = tmp_dist;
                    }
                    else min.first = dx, min.second = dy, idx = board[dx][dy], dist = tmp_dist;
                }
            }
            q.push({dx, dy, tmp_dist});
        }
    }
    if(min.first == -1 && min.second == -1){
        fuel = -1; return;
    }
    fuel -= dist;
    if(fuel < 0) return;
    find_dest(min.first, min.second, idx);
    board[min.first][min.second] = 0;
}



int main(){
    cin >> N >> M >> fuel;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }
    cin >> taxi_x >> taxi_y;
    taxi_x--, taxi_y--;
    v.resize(M + 2);
    int a, b, dx, dy;
    for(int i = 2; i <= M + 1; i++){
        cin >> a >> b >> dx >> dy;
        a--, b--, dx--, dy--;
        board[a][b] = i;
        v[i].first = dx, v[i].second = dy;
    }
    
    while(!chk_map()){
        foo();
        if(fuel < 0){
            cout << -1;
            return 0;
        }
    }
    cout << fuel;
}
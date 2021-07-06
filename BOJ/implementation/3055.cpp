#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define pii pair<int, int>

char board[51][51];
bool chk[51][51];
int water[51][51];
int arr[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int R, C, Sx, Sy;

void fill_water(int x, int y){
    queue<pair<pii, int>> q;
    q.push({{x,y}, 0});

    pii tmp;
    int cnt = 0;
    while(!q.empty()){
        tmp = q.front().first;
        cnt = q.front().second + 1;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy  >= C || board[dx][dy] == 'X' || board[dx][dy] == 'D' 
                || (water[dx][dy] != -1 && water[dx][dy] <= cnt)) continue;
            water[dx][dy] = cnt;
            q.push({{dx, dy}, cnt});
        }
    }   
}

int BFS(){
    memset(chk, false, sizeof(chk));
    queue <pair<pii, int>> q;
    q.push({{Sx,Sy}, 0});
    chk[Sx][Sy] = true;

    pii tmp;
    int cnt;
    while(!q.empty()){
        tmp = q.front().first;
        cnt = q.front().second + 1;
        q.pop();

        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dx][dy] || board[dx][dy] == 'X' || (water[dx][dy] != -1 && water[dx][dy] <= cnt)) continue;
            if(board[dx][dy] == 'D') return cnt;
            chk[dx][dy] = true;
            q.push({{dx, dy }, cnt});
        }
    }
    
    return -1;
}

int main(){
    memset(water, -1, sizeof(water));
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') Sx = i, Sy = j;
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == '*') water[i][j] = 0, fill_water(i, j);
        }
    }
    
    int answer = BFS();
    if(answer == -1) cout << "KAKTUS\n";
    else cout << answer << '\n';
}
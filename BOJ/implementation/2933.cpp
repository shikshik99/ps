#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int R, C, N;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[101][101];
bool chk[101][101];

bool cmp(pii a, pii b){
    return a.first > b.first ? true : false;
}

bool BFS(int x, int y){
    queue <pii> q;
    chk[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dx][dy] || board[dx][dy] == '.') continue;
            chk[dx][dy] = true;
            q.push({dx,dy});
            if(dx == R - 1) return true;
        }
    }
    return false;
}

void down(int x, int y){
    memset(chk, false, sizeof(chk));
    queue <pii> q;
    vector <pii> v;
    chk[x][y] = true;
    q.push({x,y}), v.push_back({x,y});
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dx][dy] || board[dx][dy] == '.') continue;
            chk[dx][dy] = true;
            q.push({dx,dy}), v.push_back({dx,dy});
        }
    }

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) board[v[i].first][v[i].second] = '.';
    while(1){
        bool flag = false;
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == R - 1){
                flag = true; break;
            }
        }
        if(flag) break;
        for(int i = 0; i < v.size(); i++){
            int dx = v[i].first + arr[1][0];
            int dy = v[i].second + arr[1][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || board[dx][dy] == '.') continue;
            if(board[dx][dy] == 'x'){flag = true; break;}
            if(flag) break;
        }
        if(flag) break;
        for(int i = 0; i < v.size(); i++) v[i].first++;
    }
    for(int i = 0; i < v.size(); i++) board[v[i].first][v[i].second] = 'x';
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cin >> board[i][j];
    }
    cin >> N;
    
    int point;
    bool flag = true;
    while(N--){
        cin >> point;
        point--;
        point = (R - 1) - point;
        if(flag){
            for(int i = 0; i < C; i++){
                if(board[point][i] == '.') continue;
                else {
                    board[point][i] = '.'; break;
                }
            }
        }
        else{
            for(int i = C-1; i >= 0; i--){
                if(board[point][i] == '.') continue;
                else {
                    board[point][i] = '.'; break;
                }
            }
        }
        flag ^= true;
        memset(chk, false, sizeof(chk));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(board[i][j] == '.' || chk[i][j]) continue;
                if(BFS(i, j) == false){
                    down(i, j);
                }
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}
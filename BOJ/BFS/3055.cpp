#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std;
using pii = pair <int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector <pii> v;
int water[MAX][MAX];
char board[MAX][MAX];
bool chk[MAX][MAX];
int R, C, sx, sy, ex, ey;

void water_BFS(){
    for(int i = 0; i < R; i++) fill(water[i], water[i] + C, MAX * MAX + 1);
    memset(chk, false, sizeof(chk));
    queue <pair<int, pii>> q;
    for(auto it : v){
        int x = it.first;
        int y = it.second;
        chk[x][y] = true;
        water[x][y] = 0;
        q.push({0, {x, y}});
    }

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first + 1; 
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dx][dy] || water[dx][dy] <= cnt || board[dx][dy] == 'X' || board[dx][dy] == 'D' || board[dx][dy] == 'S') continue;
            chk[dx][dy] = true;
            q.push({cnt, {dx, dy}});
            water[dx][dy] = cnt;
        }
    }
}

int BFS(){
    memset(chk, false, sizeof(chk));
    queue <pair<int, pii>> q;
    chk[sx][sy] = true;
    q.push({0, {sx, sy}});

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first + 1; 
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dx][dy] || water[dx][dy] <= cnt || board[dx][dy] == 'X') continue;
            if(dx == ex && dy == ey) return cnt;
            chk[dx][dy] = true;
            q.push({cnt, {dx, dy}});
        }
    }
    
    return -1;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == '*') v.push_back({i, j});
            if(board[i][j] == 'S') sx = i, sy = j;
            if(board[i][j] == 'D') ex = i, ey = j;
        }
    }

    water_BFS();
    int answer = BFS();
    if(answer == -1) cout << "KAKTUS\n";
    else cout << answer << '\n';
}
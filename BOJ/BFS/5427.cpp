#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector <pii> v;
char board[MAX][MAX];
bool chk[MAX][MAX];
int fire[MAX][MAX];
int N, M, sx, sy;

void input(){  
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == '@') sx = i, sy = j;
            if(board[i][j] == '*') v.push_back({i, j}), fire[i][j] = 0;
        }
    }
}

void clear(){
    memset(board, 0, sizeof(board));
    memset(fire, -1, sizeof(fire));
    v.clear();
}

void fire_BFS(){
    memset(chk, false, sizeof(chk));
    queue <pair<int, pii>> q;
    for(pii it : v){
        int x = it.first;
        int y = it.second;
        chk[x][y] = true;
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
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || board[dx][dy] == '#' || fire[dx][dy] != -1) continue;
            chk[dx][dy] = true;
            fire[dx][dy] = cnt;
            q.push({cnt, {dx, dy}});
        }
    }
}

int BFS(){
    if(sx == 0 || sx == N - 1 || sy == 0 || sy == M - 1) return 1;
    memset(chk, false, sizeof(chk));

    queue <pair <int, pii>> q;
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
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || board[dx][dy] == '#' || (fire[dx][dy] != -1 && fire[dx][dy] <= cnt)) continue;
            if(dx == 0 || dx == N - 1 || dy == 0 || dy == M - 1) return cnt + 1;
            chk[dx][dy] = true;
            q.push({cnt, {dx, dy}});
        }
    }
    return -1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        clear();
        input();
        fire_BFS();
        int answer = BFS();
        if(answer == -1) cout << "IMPOSSIBLE\n";
        else cout << answer << '\n';
    }
}
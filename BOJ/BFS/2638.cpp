#include <bits/stdc++.h>
#define MAX 101
using namespace std;
using pii = pair <int, int>;

vector <pii> cheese;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[MAX][MAX];
bool chk[MAX][MAX];
bool air[MAX][MAX];
int N, M;
int cnt = 0;

void air_BFS(){
    queue <pii> q;
    
    q.push({0, 0});
    air[0][0] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || air[dx][dy] || board[dx][dy] == '1') continue;
            air[dx][dy] = true;
            q.push({dx, dy});
        }
    }
}

void cheese_BFS(int sx, int sy){
    queue <pii> q;
    q.push({sx, sy});
    chk[sx][sy] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int air_cnt = 0;
        for(int i = 0; i < 4; i++){
            int dx =  x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy]) continue;
            if(board[dx][dy] == '0'){
                if(air[dx][dy]) air_cnt++;
                continue;
            }
            q.push({dx, dy});
            chk[dx][dy] = true;
        }
        if(air_cnt >= 2) cheese.push_back({x, y}), cnt--;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == '1') cnt++;
        }
    }
    
    int answer = 0, x, y;
    while(cnt){
        memset(air, false, sizeof(air));
        memset(chk, false, sizeof(chk));
        answer++;
        cheese.clear();
        air_BFS();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(chk[i][j] || board[i][j] == '0') continue;
                cheese_BFS(i, j);
            }
        }
        for(pii it : cheese){
            int x = it.first;
            int y = it.second;
            board[x][y] = '0';
        }
    }

    cout << answer << '\n';
}

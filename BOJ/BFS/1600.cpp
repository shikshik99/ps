#include <bits/stdc++.h>
#define MAX 201
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int answer[32][MAX][MAX];
int board[MAX][MAX];
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1} ,{0, 1}};
int horse[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
int N, M, K;

void BFS(){
    queue <piii> q;
    
    answer[K][0][0] = 0;
    q.push({K, {0, 0}});
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int k = q.front().first;
        int cost = answer[k][x][y];
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy]) continue;
            if(answer[k][dx][dy] <= cost + 1) continue;
            q.push({k, {dx, dy}});
            answer[k][dx][dy] = cost + 1;
        }

        if(!k) continue;
        for(int i = 0; i < 8; i++){
            int dx = x + horse[i][0];
            int dy = y + horse[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy]) continue;
            if(answer[k - 1][dx][dy] <= cost + 1) continue;
            q.push({k - 1, {dx, dy}});
            answer[k - 1][dx][dy] = cost + 1;
        }
    }
}

int main(){
    cin >> K >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> board[i][j];
    }

    for(int i = 0; i <= K; i++){
        for(int j = 0; j < N; j++) fill(answer[i][j], answer[i][j] + M, INF);
    }

    BFS();

    int ret = INF;
    for(int i = 0; i <= K; i++){
        ret = min(ret, answer[i][N - 1][M - 1]);
    }

    cout << (ret == INF ? -1 : ret) << '\n';
}


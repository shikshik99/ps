#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
using pii = pair <int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue <pair<int, pii>> q;
int board[MAX][MAX];
bool chk[MAX][MAX] = {false, };
int N, M;

int BFS(int x, int y){
    chk[x][y] = true;
    q.push({0, {x, y}});
    while(!q.empty()){
        pii tmp = q.front().second;
        int cnt = q.front().first + 1;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx == N - 1 && dy == M - 1) return cnt + 1;
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || !board[dx][dy]) continue;
            chk[dx][dy] = true;
            q.push({cnt, {dx, dy}});
        }
    }

    return 0;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) scanf("%1d", &board[i][j]);
    }

    cout << BFS(0, 0) << '\n';
}
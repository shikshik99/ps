#include <iostream>
#include <queue>
#define MAX 1001
#define reach dx == N - 1 && dy == M - 1
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int board[MAX][MAX];
bool chk[2][MAX][MAX] = {false, }; // 3차원을 이용하지 않으면 벽을 부수고 이동한 상태에서 빈 곳을 가면 벽을 안 부순 상태에서는 그 빈칸에 도달하지 못함.
int N, M;

int BFS(){
    if(N == 1 && M == 1) return 1;
    queue <pair<pii, pii>> q;
    q.push({{0, 1}, {0, 0}});
    chk[0][0][0] = true;
    while(!q.empty()){
        int flag = q.front().first.first;
        int cnt = q.front().first.second + 1;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[flag][dx][dy]) continue;
            if(reach) return cnt;
            if(board[dx][dy]){
                if(flag) continue;
                q.push({{1, cnt}, {dx, dy}});
                chk[1][dx][dy] = true;
            }
            else {
                q.push({{flag, cnt}, {dx, dy}});
                chk[flag][dx][dy] = true;
            }
        }
    }

    return -1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) scanf("%1d", &board[i][j]);
    }

    cout << BFS() << '\n';
}
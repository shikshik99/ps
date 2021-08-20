#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

int arr[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int board[MAX][MAX];
bool chk[MAX][MAX];
int T, N, M, K;

void dfs(int x, int y){
    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || !board[dx][dy]) continue;
        dfs(dx, dy);
    }
}

int dfs_all(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!chk[i][j] && board[i][j]) dfs(i, j), ret++;
        }
    }

    return ret;
}

int main(){
    cin >> T;
    while(T--){
        memset(board, 0, sizeof(board));
        memset(chk, false, sizeof(chk));
        cin >> N >> M >> K;
        int x, y;
        while(K--) cin >> x >> y, board[x][y] = 1;
        cout << dfs_all() << '\n';
    }
}

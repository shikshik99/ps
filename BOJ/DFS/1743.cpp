#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int board[MAX][MAX];
bool chk[MAX][MAX];
int N, M, K;

int dfs(int x, int y){
    int ret = 1;

    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || !board[dx][dy]) continue;
        ret += dfs(dx, dy);
    }

    return ret;
}

int dfs_all(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] && !chk[i][j]) ret = max(ret, dfs(i, j));
        }
    }
    
    return ret;
}

int main(){
    memset(chk, false, sizeof(chk));
    memset(board, 0, sizeof(board));
    cin >> N >> M >> K;
    int x, y;
    while(K--) cin >> x >> y, board[x - 1][y - 1] = 1;

    cout << dfs_all() << '\n';
}

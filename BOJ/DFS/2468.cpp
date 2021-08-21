#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int board[MAX][MAX];
bool chk[MAX][MAX];
int N;

void dfs(int x, int y, int high){
    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || board[dx][dy] <= high) continue;
        dfs(dx, dy, high);
    }
}

int dfs_all(int high){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!chk[i][j] && board[i][j] > high) dfs(i, j, high), ret++;
        }
    }

    return ret;
}

int main(){
    cin >> N;
    
    int maxx = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j], maxx = max(maxx, board[i][j]);
    }

    int answer = 0;
    for(int i = 0; i <= maxx; i++){
        memset(chk, false, sizeof(chk));
        answer = max(answer, dfs_all(i));
    }

    cout << answer << '\n';
}

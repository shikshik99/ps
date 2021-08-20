#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int arr[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char board[MAX][MAX];
bool chk[MAX][MAX];
int N;

void convert_rg(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }
}

void dfs(int x, int y, char color){
    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || board[dx][dy] != color) continue;
        dfs(dx, dy, color);
    }
}

int dfs_all(){
    int ret = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!chk[i][j]) dfs(i, j, board[i][j]), ret++;
        }
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }
    
    memset(chk, false, sizeof(chk));
    cout << dfs_all() << ' ';
    convert_rg();
    memset(chk, false, sizeof(chk));
    cout << dfs_all() << '\n';
}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool chk[51][51];
char board[51][51];
int D[51][51];
int N, M;

int DFS(int x, int y){
    int &ret = D[x][y];
    if(ret != -1) return ret;

    ret = 1;
    
    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int num = (board[x][y] - '0');
        int dx = x + (num * arr[i][0]);
        int dy = y + (num * arr[i][1]);
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy] == 'H') continue;
        if(chk[dx][dy]) cout << -1, exit(0);
        ret = max(ret, DFS(dx, dy) + 1);
    }
    chk[x][y] = false;

    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    memset(chk, false, sizeof(chk));
    memset(D, -1, sizeof(D));
    cout << DFS(0,0) << '\n';
}
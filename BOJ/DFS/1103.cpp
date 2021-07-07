#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int board[51][51], D[51][51];
int arr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool chk[51][51];

int DFS(int x, int y){
    if(D[x][y] != -1) return D[x][y];

    D[x][y] = 1;
    chk[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x + (arr[i][0] * board[x][y]);
        int dy = y + (arr[i][1] * board[x][y]);
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy] == -1) continue;
        if(chk[dx][dy]) cout << -1, exit(0);
        D[x][y] = max(D[x][y], DFS(dx, dy) + 1);
    }

    chk[x][y] = false;
    return D[x][y];
}

int main(){
    memset(chk, false, sizeof(chk));
    memset(D, -1, sizeof(D));

    char ch;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> ch;
            if(ch == 'H') board[i][j] = -1;
            else board[i][j] = (ch - '0');
        }
    }
    
    cout << DFS(0, 0);
}

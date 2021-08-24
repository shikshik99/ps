#include <iostream>
#define MAX 6
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool chk[MAX][MAX] = {false, };
char board[MAX][MAX];
int N, M, K;

int DFS(int x, int y, int cnt){
    if(cnt > K) return 0;
    if(x == 0 && y == M - 1) return cnt == K ? 1 : 0;
    int ret = 0;
    chk[x][y] = true;

    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || board[dx][dy] == 'T') continue;
        ret += DFS(dx, dy,  cnt + 1);
    }

    chk[x][y] = false;
    
    return ret;
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    cout << DFS(N - 1, 0, 1) << '\n';
}
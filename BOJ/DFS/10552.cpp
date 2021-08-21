#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int board[MAX];
bool chk[MAX] = {false, };
int N, M, P;

int dfs(int cur){
    chk[cur] = true;
    int ret = 0;
    
    int next = board[cur];
    if(next != -1 && chk[next]) cout << -1 << '\n', exit(0);
    if(next != -1) ret += dfs(next) + 1;

    return ret;
}

int main(){
    memset(board, -1, sizeof(board));
    cin >> N >> M >> P;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        if(board[b] != -1) continue;
        board[b] = a;
    }

    cout << dfs(P) << '\n';
}
#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int board[MAX][MAX];
bool chk[MAX];
bool answer[MAX][MAX] = {false, };
int N;

void dfs(int cur){
    for(int i = 0; i < N; i++){
        if(!chk[i] && board[cur][i]) chk[i] = true, dfs(i);
    }
}

void possible(int cur){
    for(int i = 0; i < N; i++){
        if(chk[i]) answer[cur][i] = true;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    for(int i = 0; i < N; i++){
        memset(chk, false, sizeof(chk));
        dfs(i);
        possible(i);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}
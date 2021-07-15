#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int, int>

char board[101][101];
bool chk[101][101];
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N;

void BFS(int x, int y){
    char target = board[x][y];
    queue <pii> q;
    q.push({x, y});

    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || board[dx][dy] != target) continue;
            chk[dx][dy] = true;
            q.push({dx, dy});
        }    
    }
}

void conv_red_green(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    int ans1 = 0, ans2 = 0;
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!chk[i][j]) BFS(i, j), ans1++;
        }
    }
    
    conv_red_green();
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!chk[i][j]) BFS(i, j), ans2++;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}
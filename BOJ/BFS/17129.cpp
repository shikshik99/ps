#include <bits/stdc++.h>
#define MAX 3001
using namespace std;
using pii = pair <int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[MAX][MAX];
bool chk[MAX][MAX];
int N, M;

int BFS(int a, int b){
    queue <pii> q;
    chk[a][b] = true;
    q.push({a, b});

    int ret = 0;
    while(!q.empty()){
        ret++;
        int qsize = q.size();
        while(qsize--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy] == '1' || chk[dx][dy]) continue;
                if(board[dx][dy] != '0') return ret;
                q.push({dx, dy});
                chk[dx][dy] = true;
            }
        }
    }

    return -1;
}

int main(){
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == '2') x = i, y = j;
        }
    }

    int answer = BFS(x, y);
    if(answer == -1) cout << "NIE\n";
    else cout << "TAK\n" << answer << '\n';
}
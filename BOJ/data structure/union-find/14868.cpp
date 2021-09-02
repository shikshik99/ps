#include <iostream>
#include <queue>
#include <cstring>
#define MAX 2001
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int P[100001];
int board[MAX][MAX];
int N, K;
queue <pii> q;

int find(int a){
    if(P[a] < 0) return a;
    return P[a] = find(P[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(P[a] > P[b]) {
        P[b] += P[a];
        P[a] = b;
    }
    else{
        P[a] += P[b];
        P[b] = a;
    }
}

void BFS(){
    int qsize = q.size();
    while(qsize--){
        int x = q.front().first;
        int y = q.front().second;
        int tmp = board[x][y];
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || board[dx][dy] != -1) continue;
            q.push({dx, dy});
            board[dx][dy] = tmp;
            for(int j = 0; j < 4; j++){
                int ddx = dx + arr[j][0];
                int ddy = dy + arr[j][1];
                if(ddx < 0 || ddx >= N || ddy < 0 || ddy >= N || board[ddx][ddy] == -1) continue;
                merge(tmp, board[ddx][ddy]);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(P, -1, sizeof(P));
    memset(board, -1, sizeof(board));
    cin >> N >> K;

    int x, y;
    for(int i = 0; i < K; i++){
        cin >> y >> x;
        y--, x--;
        board[x][y] = i;
        q.push({x, y});
        for(int j = 0; j < 4; j++){
            int dx = x + arr[j][0];
            int dy = y + arr[j][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || board[dx][dy] == -1) continue;
            merge(board[x][y], board[dx][dy]);
        }
    }
    int answer = 0;
    while(P[find(0)] > -K){
        answer++;
        BFS();
    }

    cout << answer << '\n';
}

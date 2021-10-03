#include <bits/stdc++.h>
#define MAX 51
using namespace std;

struct node{
    int x, y, cost;
    node(int dx, int dy, int co) : x(dx), y(dy), cost(co) {}
};

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[MAX][MAX];
int answer[MAX][MAX];
int N;

void BFS(){
    queue <node> q;

    answer[0][0] = 0;
    q.push(node(0,0,0));

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
            if(board[dx][dy] == '0'){
                if(answer[dx][dy] != -1 && cost + 1 >= answer[dx][dy]) continue;
                answer[dx][dy] = cost + 1;
                q.push(node(dx, dy, cost + 1));
            }
            else{
                if(answer[dx][dy] != -1 && cost >= answer[dx][dy]) continue;
                answer[dx][dy] = cost;
                q.push(node(dx, dy, cost));
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    memset(answer, -1, sizeof(answer));
    BFS();
    cout << answer[N - 1][N - 1];
}
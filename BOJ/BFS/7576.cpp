#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
using pii = pair<int, int>;

vector <pii> v;
int arr[4][2] = {{-1 ,0}, {1 ,0}, {0 ,-1}, {0 ,1}};
int board[MAX][MAX];
bool chk[MAX][MAX] = {false, };
int N, M;

bool possible(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            if(!board[i][j]) return false;
        }
    }

    return true;
}

int BFS(){
    queue <pii> q;
    int ret = 0;
    
    for(auto it : v){
        int x = it.first;
        int y = it.second;
        chk[x][y] = true;
        q.push({x, y});
    }

    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || board[dx][dy] == -1) continue;
                chk[dx][dy] = true;
                board[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
        ret++;
    }

    if(possible()) return ret - 1;
    else return -1;
}

int main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) v.push_back({i, j});
        }
    }

    cout << BFS() << '\n';
}
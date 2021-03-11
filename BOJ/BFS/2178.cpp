#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int,int>

int N, M, maze[101][101];
int chk[101][101];
queue <pii>q;

void BFS(){
    pii tmp;
    int arr[4][2] = {{1, 0}, {-1, 0}, {0, -1} , {0, 1}};
    int cnt;
    q.push({0,0});
    while(!q.empty()){
        tmp = q.front(), q.pop(), cnt = chk[tmp.first][tmp.second];
        for(int i = 0; i < 4; i++){
            tmp.first += arr[i][0], tmp.second += arr[i][1];
            if(tmp.first >=0 && tmp.first < N && tmp.second >= 0 && tmp.second < M && !chk[tmp.first][tmp.second] && maze[tmp.first][tmp.second]){
                q.push(tmp), chk[tmp.first][tmp.second] = cnt + 1;
            }
            tmp.first -= arr[i][0], tmp.second -= arr[i][1];
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) scanf("%1d", &maze[i][j]);
    }
    BFS();
    cout << chk[N-1][M-1] + 1;
}
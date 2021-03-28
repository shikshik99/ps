#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define pii pair<int, int>

char map[100][100];
bool chk[100][100];
int arr[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int N, M, K, answer = 0;

void BFS(int x, int y){
    queue <pii> q;
    int cnt = 1;
    chk[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || map[dx][dy] == '.') continue;
            chk[dx][dy] = true, cnt++, q.push({dx,dy});
        }        
    }
    answer = answer > cnt ? answer : cnt;
}

int main(){
    cin >> N >> M >> K;
    int x, y;
    memset(chk, false, sizeof(chk)), memset(map, '.', sizeof(map));
    for(int i = 0; i < K; i++){
        cin >> x >> y, x--, y--;
        map[x][y] = '#';
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == '#' && !chk[i][j]) BFS(i,j);
        }
    }
    cout << answer;
}
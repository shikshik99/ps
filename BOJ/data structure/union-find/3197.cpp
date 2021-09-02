#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1501
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int P[MAX * MAX];
pii pos[2];
char map[MAX][MAX];
int N, M;
queue <pii> q;

int find(int a){
    if(P[a] < 0) return a;
    return P[a] = find(P[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    P[b] = a;
}

void BFS(){
    int qsize = q.size();
    while(qsize--){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || map[dx][dy] != 'X') continue;
            map[dx][dy] = '.';
            q.push({dx, dy});
            merge(x * MAX + y, dx * MAX + dy);
            for(int j = 0; j < 4; j++){
                int ddx = dx + arr[j][0];
                int ddy = dy + arr[j][1];
                if(ddx < 0 || ddx >= N || ddy < 0 || ddy >= M || map[ddx][ddy] == 'X') continue;
                merge(dx * MAX + dy, ddx * MAX + ddy);
            }
        }
    }
}

int main(){
    memset(P, -1, sizeof(P));
    cin >> N >> M;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        getchar();
        for(int j = 0; j < M; j++){
            map[i][j] = getchar();
            if(map[i][j] == 'L') pos[cnt].first = i, pos[cnt].second = j, cnt++;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'X') continue;
            q.push({i, j});
            for(int d = 0; d < 4; d++){
                int dx = i + arr[d][0];
                int dy = j + arr[d][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= M || map[dx][dy] == 'X') continue;
                merge(i * MAX + j, dx * MAX + dy);
            }
        }
    }
    
    int answer = 0;
    int x1 = pos[0].first, y1 = pos[0].second, x2 = pos[1].first, y2 = pos[1].second;
    while(find(x1 * MAX + y1) != find(x2 * MAX + y2)){
        answer++;
        BFS();
    }
    cout << answer << '\n';
}
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301
using namespace std;
using pii = pair<int, int>;

int arr[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool chk[MAX][MAX];
int N, sx, sy, ex, ey;

int BFS(){
    queue <pii> q;
    chk[sx][sy] = true;
    q.push({sx, sy});

    int ret = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int x = q.front().first;
            int y = q.front().second;
            if(x == ex && y == ey) return ret;
            q.pop();
            for(int i = 0; i < 8; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy]) continue;
                chk[dx][dy] = true;
                q.push({dx, dy});
            }
        }
        ret++;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> sx >> sy >> ex >> ey;
        memset(chk, false, sizeof(chk));
        cout << BFS() << '\n';
    }
}
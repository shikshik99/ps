#include <iostream>
#include <queue>
#include <cstring>
#define MAX 31
using namespace std;
using pii = pair<int, int>;

int arr[6][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}, {1, 0, 0}, {-1, 0, 0}};
char building[MAX][MAX][MAX];
bool chk[MAX][MAX][MAX];
int L, R, C;
int sl, sx, sy;

void input(){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++) {
                cin >> building[i][j][k];
                if(building[i][j][k] == 'S') sl = i, sx = j, sy = k;
            }
        }
    }
}

int BFS(){
    memset(chk, false, sizeof(chk));
    queue<pair<pii, pii>> q;
    q.push({{0, sl}, {sx, sy}});
    chk[sl][sx][sy] = true;
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int l = q.front().first.second;
        int cnt = q.front().first.first + 1;
        q.pop();
        for(int i = 0; i < 6; i++){
            int dl = l + arr[i][0];
            int dx = x + arr[i][1];
            int dy = y + arr[i][2];
            if(dl < 0 || dl >= L || dx < 0 || dx >= R || dy < 0 || dy >= C || chk[dl][dx][dy] || building[dl][dx][dy] == '#') continue;
            if(building[dl][dx][dy] == 'E') return cnt;
            chk[dl][dx][dy] = true;
            q.push({{cnt, dl}, {dx, dy}});
        }
    }
    return -1;
}

int main(){
    while((cin >> L >> R >> C) && L && R && C){
        memset(building, 0, sizeof(building));
        input();
        int answer = BFS();
        if(answer == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << answer << " minute(s).\n";    
    }
}
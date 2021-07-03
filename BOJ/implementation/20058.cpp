#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

bool chk[64][64];
int arr[64][64], temp[64][64];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, Q, ma;

int BFS(int x, int y){
    int sizz = 0;
    queue <pii>q;
    q.push({x,y});
    chk[x][y] = true;
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        sizz++;
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + dir[i][0];
            int dy = tmp.second + dir[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || !arr[dx][dy]) continue;
            q.push({dx,dy});
            chk[dx][dy] = true;
        }
    }
    return sizz;
}

void chk_ice(){
    int cnt;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j]){
                cnt = 0;
                for(int k = 0; k < 4; k++){
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];
                    if(dx < 0 || dx >= N || dy < 0 || dy >= N || !arr[dx][dy]) continue;
                    cnt++;
                }
                if(cnt < 3) chk[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(chk[i][j]) arr[i][j]--;
        }
    }
}

void rot(int x, int y, int L){
    for(int i = x; i < x + ma; i++){
        for(int j = y; j < y + ma; j++){
            temp[j - y][x + ma - i - 1] = arr[i][j];
        }
    }
    
    for(int i = x; i < x + ma; i++){
        for(int j = y; j < y + ma; j++){
            arr[i][j] = temp[i - x][j - y];
        }
    }
}

int main(){
    memset(temp, 0, sizeof(temp));
    

    int L;
    cin >> N >> Q;

    N = pow(2, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }

    while(Q--){
        cin >> L;
        if(L){
            ma = pow(2, L);
            for(int i = 0; i < N; i += ma){
                for(int j = 0; j < N; j += ma){
                    rot(i, j, L);
                }
            }
        }
        memset(chk, false, sizeof(chk));
        chk_ice();
    }
    
    long long answer = 0;
    int sizz = 0;

    memset(chk, false, sizeof(chk));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            answer += arr[i][j];
            if(!chk[i][j] && arr[i][j]) sizz = max(sizz, BFS(i, j));
        }
    }
    cout << answer << '\n' << sizz << '\n';
}
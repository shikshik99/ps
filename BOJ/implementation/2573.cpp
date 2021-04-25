#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair <int, int>

int n, m, cnt = 0;
queue <pii>q;
bool flag = false;
bool chk[301][301];
int board[301][301], tmp[301][301];
int arr[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

void melt(){
    memset(tmp, 0, sizeof(tmp));
    int a = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!board[i][j]) continue;
            for(int k = 0; k < 4; k++){
                int dx = i + arr[k][0];
                int dy = j + arr[k][1];
                if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                if(!board[dx][dy]) a++;
            }
            tmp[i][j] = board[i][j] - a, a = 0;
            if(tmp[i][j] < 0) tmp[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void BFS(){
    int a = 0;
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!board[i][j] || chk[i][j]) continue;
            q.push({i,j});
            chk[i][j] = true;
            while(!q.empty()){
                pii b = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int dx = b.first + arr[i][0];
                    int dy = b.second + arr[i][1];
                    if(dx < 0 || dx >= n || dy < 0 || dy >= m || !board[dx][dy] || chk[dx][dy]) continue;
                    q.push({dx,dy}), chk[dx][dy] = true;
                }
            }
            a++;
        }
    }
    if(!a) cnt = 0, flag = true;
    else if(a == 1) cnt++;
    else cnt++, flag = true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }
    while(1){
        melt();
        BFS();
        if(flag){
            cout << cnt;
            return 0;
        }
    }
}
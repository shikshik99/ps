#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int arr[51][51];
bool chk[51][51];
queue <pair<int, int>>q;
vector <int>v;
int T, garo, sero, K;

void bfs(int x, int y){
    int a,b;
    int f[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push(make_pair(x,y));
    chk[x][y] = true;
    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            a = q.front().first + f[i][0];
            b = q.front().second + f[i][1];
            if(a < 0 || a >= garo || b < 0 || b >= sero || chk[a][b] || !arr[a][b]) continue;            
            chk[a][b] = true;
            q.push(make_pair(a,b));
        }
        q.pop();
    }
}

void foo(){
    int cnt = 0;
    for(int i = 0; i < garo; i++){
        for(int j = 0; j < sero; j++){
            if(chk[i][j] || !arr[i][j]) continue;
            bfs(i, j); cnt++;
        }
    }
    v.push_back(cnt);
}

int main(){
    cin >> T;
    int x, y;
    for(int i = 0; i < T; i++){
        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));
        cin >> garo >> sero >> K;
        for(int j = 0; j < K; j++){
            cin >> x >> y;
            arr[x][y] = 1;
        }
        foo();
    }
    for(auto a : v) cout << a << '\n';
}
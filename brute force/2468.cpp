#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101][101];
bool chk[101][101];
int N, rain = 100000001, ma = 0;
queue <pair<int,int>>q;

void bfs(int a, int b){
    int qq[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    int x, y;
    q.push(make_pair(a, b));
    chk[a][b] = true;

    while(!q.empty()){
        for(int i = 0; i < 4; i++){
            x = q.front().first + qq[i][0];
            y = q.front().second+ qq[i][1];
            if(x < 0 || x >= N || y < 0 || y >= N || arr[x][y] <= rain || chk[x][y]) continue;
            else{
                q.push(make_pair(x,y));
                chk[x][y] = true;
            }
        }
        q.pop();
    }
}

int foo(){
    int ans = 0, area = 0;
    rain -= 1;
    while(rain <= ma){
        memset(chk, false, sizeof(chk));
        area = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(chk[i][j] || arr[i][j] <= rain) continue;
                else {bfs(i, j); area++;}
            }
        }
        ans = max(ans, area);
        rain++;
    }
    return ans;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            rain = min(arr[i][j], rain);
            ma = max(arr[i][j], ma);
        }
    }

    cout << foo();
}
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int board[MAX][MAX] = {0, };
bool chk[MAX][MAX] = {false, };
vector <int> v;
int N, M, K;

int dfs(int x, int y){
    chk[x][y] = true;
    int ret = 1;
    
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || board[dx][dy] || chk[dx][dy]) continue;
        ret += dfs(dx, dy);
    }

    return ret;
}

int dfs_all(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!board[i][j] && !chk[i][j]) v.push_back(dfs(i, j)), ret++;
        }
    }

    return ret;
}

void draw(int x, int dx, int y, int dy){
    for(int i = x; i < dx; i++){
        for(int j = y; j < dy; j++){
            board[i][j] = 1;
        }
    }
}

int main(){
    cin >> N >> M >> K;
    int x, y, dx, dy;
    for(int i = 0; i < K; i++){
        cin >> y >> x >> dy >> dx;
        draw(x, dx, y, dy);
    }

    cout << dfs_all() << '\n';
    sort(v.begin(), v.end());
    for(auto it : v) cout << it << ' ';
}
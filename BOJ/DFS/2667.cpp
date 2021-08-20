#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int board[MAX][MAX];
bool chk[MAX][MAX] = {false, };
vector <int> answer;
int N;

int dfs(int x, int y){
    chk[x][y] = true;
    
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || !board[dx][dy]) continue;
        ret += dfs(dx, dy);
    }

    return ret;
}

int dfs_all(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] && !chk[i][j]) answer.push_back(dfs(i, j)), ret++;
        }
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) scanf("%1d", &board[i][j]);
    }

    cout << dfs_all() << '\n';
    sort(answer.begin(), answer.end());
    for(auto it : answer) cout << it << '\n';
}
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool chk[MAX][MAX];
char board[MAX][MAX];
vector <vector<int>> v;
int N, M, pointx, pointy, point_cnt;

int longest_path(int x, int y, int cnt){
    chk[x][y] = true;
    if(point_cnt < cnt) pointx = x, pointy = y, point_cnt = cnt;
    int ret = cnt;
    
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy] || board[dx][dy] == '#') continue;
        ret = max(ret, longest_path(dx, dy, cnt + 1));
    }

    chk[x][y] = false;
    
    return ret;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> M >> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) cin >> board[i][j];
        }

        pointx = pointy = point_cnt = 0;
        memset(chk, false, sizeof(chk));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                if(board[i][j] == '.') longest_path(i, j, 0), i = N, j = M;
            }
        }
        memset(chk, false, sizeof(chk));
        int answer = longest_path(pointx, pointy, 0);
        cout << "Maximum rope length is " << answer << ".\n";
    }
}
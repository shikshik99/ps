#include <bits/stdc++.h>
#define MAX 51
using namespace std;
using pii = pair<int, int>;

vector <pii> v;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int origin[MAX][MAX];
int board[MAX][MAX];
bool chk_R[11], chk_G[11];
int N, M, G, R, land_cnt;
int answer = 0;

int flower(){
    int ret = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 9) ret++;
        }
    }

    return ret;
}

void BFS(){
    queue <pii> RQ;
    queue <pii> GQ;

    for(int i = 0; i < land_cnt; i++) {
        int x = v[i].first;
        int y = v[i].second;
        if(chk_R[i]){
            RQ.push({x, y});
            board[x][y] = 3;
        }
        if(chk_G[i]){
            GQ.push({x, y});
            board[x][y] = 4;
        }
    }

    while(!RQ.empty() || !GQ.empty()){
        int qsize = RQ.size();
        while(qsize--){
            int x = RQ.front().first;
            int y = RQ.front().second;
            RQ.pop();
            if(board[x][y] == 9) continue;
            board[x][y] = 6;
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= M || !(board[dx][dy] == 1 || board[dx][dy] == 2)) continue;
                board[dx][dy] = 3;
                RQ.push({dx, dy});
            }
        }

        qsize = GQ.size();
        while(qsize--){
            int x = GQ.front().first;
            int y = GQ.front().second;
            GQ.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= M || !(board[dx][dy] == 1 || board[dx][dy] == 2 || board[dx][dy] == 3)) continue;
                if(board[dx][dy] == 3) {
                    board[dx][dy] = 9;
                    continue;
                }
                board[dx][dy] = 4;
                GQ.push({dx, dy});
            }
        }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++) cout << board[i][j] << ' ';
    //     cout << '\n';
    // }

    answer = max(answer, flower());
}

void copy_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) board[i][j] = origin[i][j];
    }
}

void combination_G(int idx, int depth){
    if(depth == G){
        copy_board();
        BFS();
        return;
    }

    for(int i = idx; i < land_cnt; i++){
        if(chk_R[i]) continue;
        chk_G[i] = true;
        combination_G(i + 1, depth + 1);
        chk_G[i] = false;
    }
}

void combination_R(int idx, int depth){
    if(depth == R){
        combination_G(0, 0);
        return;
    }

    for(int i = idx; i < land_cnt; i++){
        chk_R[i] = true;
        combination_R(i + 1, depth + 1);
        chk_R[i] = false;
    }
}

int main(){
    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> origin[i][j];
            if(origin[i][j] == 2) v.push_back({i, j});
        }
    }
    
    land_cnt = v.size();
    combination_R(0, 0);
    
    cout << answer << '\n';
}
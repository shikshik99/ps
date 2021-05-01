#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define pii pair<int, int>

vector <vector<int>>board, original;
int N, M, D, answer = 0;
int arr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool chk[15] = {false, }, chk_board[15][15];
bool chk_bfs[15][15];

int calc_dist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void enemy_move(){
    for(int i = N - 1; i > 0 ; i--){
        for(int j = 0 ; j < M; j++){
            board[i][j] = board[i - 1][j];
        }
    }
    for(int i = 0; i < M; i++) board[0][i] = 0;
}

pii find_enemy(int x, int y){
    memset(chk_bfs, false, sizeof(chk_bfs));
    queue <pii> q;
    pii ret = {-1,-1};
    q.push({x, y});
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk_bfs[dx][dy] || calc_dist({x, y}, {dx, dy}) > D) continue;
            if(board[dx][dy] == 1) {
                if(ret.first == -1) ret.first = dx, ret.second = dy;
                else{
                    if(calc_dist(ret, {x, y}) > calc_dist({dx, dy}, {x, y})) ret.first = dx, ret.second = dy;
                    else if(calc_dist(ret, {x, y}) == calc_dist({dx, dy}, {x, y})){
                        if(ret.second > dy) ret.first = dx, ret.second = dy;
                    }
                    else ;
                }
            }
            chk_bfs[dx][dy] = true;
            q.push({dx,dy});
        }
    }
    return ret;
}

bool check_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) if(board[i][j] == 1) return false;
    }
    return true;
}

int kill_enemy(){
    int n = N, cnt = 0;
    while(n--){
        memset(chk_board, false, sizeof(chk_board));
        if(check_board()) return cnt;
        for(int i = 0; i < M; i++){
            if(chk[i]){
                pii target = find_enemy(N, i);
                if(target.first != -1 && target.second != -1) chk_board[target.first][target.second] = true;
            }
        }
        for(int i = N - 1; i >= 0; i--){
            for(int j = 0; j < M; j++){
                if(chk_board[i][j]) cnt++, board[i][j] = 0;
            }
        }
        enemy_move();
    }
    return cnt;
}

void copy_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) board[i][j] = original[i][j];
    }
}

void combination(int idx, int depth){
    if(depth == 3){
        copy_map();
        answer = max(answer, kill_enemy());
        return;
    }
    for(int i = idx; i < M; i++){
        if(chk[i]) continue;
        chk[i] = true;
        combination(i + 1, depth + 1);
        chk[i] = false;
    }
}

int main(){
    cin >> N >> M >> D;
    original.resize(N), board.resize(N);
    for(int i = 0; i < N; i++) original[i].resize(M), board[i].resize(M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> original[i][j];
    }
    combination(0, 0);
    
    cout << answer;
}
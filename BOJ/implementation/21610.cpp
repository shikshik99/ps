#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int, int>

bool chk[51][51];
int board[51][51];
int arr[9][2] = {{0,0}, {0, -1}, {-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int N, M;
vector <pii> cloud;

void make_cloud(){
    memset(chk, false, sizeof(chk));
    int x, y;

    for(int i = 0; i < cloud.size(); i++){
        x = cloud[i].first, y = cloud[i].second;
        chk[x][y] = true;
    }

    cloud.clear();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] >= 2 && !chk[i][j]){
                board[i][j] -= 2;
                cloud.push_back({i, j});
            }
        }
    }
}

void copy(){
    int x, y, cnt;
    for(int i = 0; i < cloud.size(); i++){
        x = cloud[i].first, y = cloud[i].second;
        cnt = 0;
        for(int i = 2; i < 9; i += 2){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || !board[dx][dy]) continue;
            cnt++;
        }
        board[x][y] += cnt;
    }
}

void rain(){
    int x, y;
    for(int i = 0; i < cloud.size(); i++){
        x = cloud[i].first, y = cloud[i].second;
        board[x][y]++;
    }
}

int chk_dist(int tmp){
    while(tmp < 0) tmp += N;
    if(tmp >= N) tmp %= N;
    return tmp;
}

void mov(int dir, int dist){
    for(int i = 0; i < cloud.size(); i++){
        cloud[i].first = chk_dist(cloud[i].first + (arr[dir][0] * dist));
        cloud[i].second = chk_dist(cloud[i].second + (arr[dir][1] * dist));
    }
}

int main(){
    int dir, dist;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }
    
    queue <pii> q;
    for(int i = 0; i < M; i++) cin >> dir >> dist, q.push({dir, dist});

    cloud.push_back({N - 1, 0}), cloud.push_back({N - 1, 1}), cloud.push_back({N - 2, 0}), cloud.push_back({N - 2, 1});
    while(M--){
        dir = q.front().first, dist = q.front().second, q.pop();
        mov(dir, dist);
        rain();
        copy();
        make_cloud();
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) answer += board[i][j];
    }

    cout << answer << '\n';
}
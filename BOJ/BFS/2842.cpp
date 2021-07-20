#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair <int, int>;

vector <pii> house;
vector <int> v;
int dir[8][2] = {{-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}, {0, -1}, {0, 1}};
int height[51][51];
char board[51][51];
bool chk[51][51];
int N, PX, PY;

bool chk_house(){
    int len = house.size();
    for(int i = 0; i < len; i++){
        int dx = house[i].first;
        int dy = house[i].second;
        if(!chk[dx][dy]) return false;
    }

    return true;
}

bool BFS(int MIN, int MAX){
    if(height[PX][PY] < MIN || height[PX][PY] > MAX) return false;

    memset(chk, false, sizeof(chk));
    queue <pii> q;
    q.push({PX, PY});
    chk[PX][PY] = true;
    
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int dx = tmp.first + dir[i][0];
            int dy = tmp.second + dir[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || height[dx][dy] < MIN || height[dx][dy] > MAX) continue;
            chk[dx][dy] = true;
            q.push({dx, dy});
        }
    }
    return chk_house();
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'P') PX = i, PY = j;
            if(board[i][j] == 'K') house.push_back({i, j});
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> height[i][j];
            v.push_back(height[i][j]);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int len = v.size();
    int l = 0, r = 0, answer = 0x6f6f6f6f;
    while(r <= len){
        while(BFS(v[l], v[r])){
            answer = min(answer, (v[r] - v[l]));
            l++;
        }
        r++;
    }

    cout << answer << '\n';
}
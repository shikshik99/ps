#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define pii pair<int, int>

vector <pii> position;
vector <pii> tmp;
bool chk[21][21];

int N, M;

bool foo(int dx, int dy, vector<vector<int>> lock){
    int x, y;
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < tmp.size(); i++){
        x = tmp[i].first - dx;
        y = tmp[i].second - dy;
        if(x < 0 || x >= N || y < 0 || y >= N) continue;
        if(lock[x][y]) break;
        chk[x][y] = true;    
    }
    
    for(int i = 0; i < position.size(); i++){
        if(!chk[position[i].first][position[i].second]) return false;
    }
    return true;
}

bool chk_key(vector<vector<int>> lock){
    int dx, dy, x, y;
    for(int i = 0; i < position.size(); i++){
        for(int j = 0; j < tmp.size(); j++){
            dx = tmp[j].first - position[i].first;
            dy = tmp[j].second - position[i].second;
            if(foo(dx, dy, lock)) return true;
        }
    }
    
    return false;
}

void rot(){
    for(int i = 0; i < tmp.size(); i++){
        tmp[i] = {tmp[i].second, M - tmp[i].first - 1};
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    N = lock.size(), M = key.size();
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!lock[i][j]) position.push_back({i, j});
        }
    }
    
    if(position.empty()) return true;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(key[i][j]) tmp.push_back({i, j});
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(chk_key(lock)) return true;
        rot();
    }
    
    return false;
}
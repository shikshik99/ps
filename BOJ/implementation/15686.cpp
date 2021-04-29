#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define pii pair<int, int>

vector <pii> house, chick;
int board[51][51];
bool combi[13];
int N, M, answer = 0x6f6f6f6f;

int foo(){
    int tmp = 0, dist;
    for(int i = 0; i < house.size(); i++){
        dist = 0x6f6f6f6f;
        for(int j = 0; j < chick.size(); j++){
            if(!combi[j]) continue;
            dist = min(dist, abs(house[i].first - chick[j].first) + abs(house[i].second - chick[j].second));
        }
        tmp += dist;
    }
    return tmp;
}

void combination(int idx, int depth, int max){
    if(depth == max){
        answer = min(answer, foo()); return;
    }
    for(int i = idx; i < chick.size(); i++){
        if(combi[i]) continue;
        combi[i] = true;
        combination(i, depth + 1, max);
        combi[i] = false;
    }
}

int main(){
    memset(combi, false, sizeof(combi));
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            if(board[i][j] == 2) chick.push_back({i,j});
        }
    }
    for(int i = 1; i <= M; i++){
        combination(0,0,i);
    }
    cout << answer;
}
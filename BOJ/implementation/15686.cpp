#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define MAX 0x6f6f6f6f

vector <pii> info, home;
int board[51][51];
bool chk[13];
int N, M;

int calc_dist(){
    int tmp, ret = 0;
    for(int i = 0; i < home.size(); i++){
        tmp = MAX;
        for(int j = 0; j < info.size(); j++){
            if(!chk[j]) continue;
            int cal = abs(home[i].first - info[j].first) + abs(home[i].second - info[j].second);
            tmp = tmp < cal ? tmp : cal;
        }
        ret += tmp;
    }
    
    return ret;
}

int combination(int idx, int depth){
    int answer = calc_dist();
    if(depth == M) return answer;

    for(int i = idx; i < info.size(); i++){
        chk[i] = true;
        answer = min(answer, combination(i + 1, depth + 1));
        chk[i] = false;
    }
    
    return answer;
}

int main(){
    memset(chk, false, sizeof(chk));

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) home.push_back({i,j});
            if(board[i][j] == 2) info.push_back({i,j});
        }
    }

    int answer = MAX;
    for(int i = 0; i < info.size() - (M - 1); i++){
        chk[i] = true;
        answer = min(answer, combination(i, 0));
        chk[i] = false;
    }

    cout << answer << '\n';
}
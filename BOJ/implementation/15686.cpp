#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 0x6f6f6f6f
using pii = pair<int, int>;

vector <pii> chicken, house;
bool chk[13] = {false, };
int N, M, sizz;

int chick_dist(){
    int ret = 0, tmp;
    for(int i = 0; i < house.size(); i++){
        tmp = MAX;
        for(int j = 0; j < sizz; j++){
            if(!chk[j]) continue;
            tmp = min(tmp, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
        }
        ret += tmp;
    }

    return ret;
}

int combination(int idx, int depth){
    if(depth == M) return chick_dist();

    int answer = MAX;

    for(int i = idx; i < sizz; i++){
        if(chk[i]) continue;
        chk[i] = true;
        answer = min(answer, chick_dist());
        answer = min(answer, combination(i + 1, depth + 1));
        chk[i] = false;
    }

    return answer;
}

int main(){
    cin >> N >> M;
    int tmp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == 1) house.push_back({i, j});
            if(tmp == 2) chicken.push_back({i, j});
        }
    }
    
    sizz = chicken.size();
    cout << combination(0, 0);
}
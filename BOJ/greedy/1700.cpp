#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair <int, int>;

int swp[MAX];
int multi[MAX];
int use[MAX];
int N, K;

bool chk_use(int num){
    for(int i = 0; i < N; i++){
        if(multi[i] == num) return true;
    }

    return false;
}

int chk_empty(){
    for(int i = 0; i < N; i++){
        if(!multi[i]) return i;
    }
    return -1;
}

int find_pos(int idx){
    fill(swp, swp + N, INF);
    pii ret;
    ret.first = -1, ret.second = -1;
    for(int i = 0; i < N; i++){
        for(int j = idx; j < K; j++){
            if(multi[i] == use[j]) {
                swp[i] = j;
                break;
            }
        }
        if(ret.second < swp[i]) ret.first = i, ret.second = swp[i];
    }

    return ret.first;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++) cin >> use[i];

    int num, answer = 0;
    pii due, tmp;
    for(int i = 0; i < K; i++) {
        num = use[i];
        if(chk_use(num)) continue;

        int idx = chk_empty();
        if(idx != -1) {
            multi[idx] = num;
            continue;
        }
        idx = find_pos(i);
        multi[idx] = num;
        answer++;
    }

    cout << answer << '\n';
}
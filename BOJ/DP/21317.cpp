#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int small_jmp[MAX], big_jmp[MAX];
int D[MAX][2];
int N, K;

int solve(int idx, bool is_jmp){
    if(idx == N) return 0;
    
    int &ret = D[idx][is_jmp];
    if(ret != -1) return ret;

    ret = solve(idx + 1, is_jmp) + small_jmp[idx];
    if(idx + 2 <= N) ret = min(ret, solve(idx + 2, is_jmp) + big_jmp[idx]);
    if(!is_jmp && idx + 3 <= N) ret = min(ret, solve(idx + 3, true) + K);
    
    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 1; i < N; i++) cin >> small_jmp[i] >> big_jmp[i];
    cin >> K;

    cout << solve(1, false) << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int T[16], P[16];
int D[16];
int N;

int solve(int idx){
    if(idx == N) return 0;
    int &ret = D[idx];
    
    if(ret != -1) return ret;

    ret = solve(idx + 1);
    if(idx + T[idx] <= N) ret = max(ret, solve(idx + T[idx]) + P[idx]);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> T[i] >> P[i];

    cout << solve(0) << '\n';
}
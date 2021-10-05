#include <bits/stdc++.h>
#define MAX 2001
using namespace std;
using ll = long long;

ll D[11][MAX];
int N, M;

ll solve(int idx, int cost){
    if(idx == N) return 1;
    if(cost > M) return 0;
    
    ll &ret = D[idx][cost];
    if(ret != -1) return ret;

    ret = 0;
    ret += solve(idx, cost + 1);
    ret += solve(idx + 1, cost * 2);

    return ret;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        cin >> N >> M;
        memset(D, -1, sizeof(D));
        cout << solve(0, 1) << '\n';
    }
    
}

#include <bits/stdc++.h>
#define MAX 10001
#define INF 0x6f6f6f6f
using namespace std;

bool chk[MAX];
int D[MAX][1000];
int N, M;

int solve(int idx, int cnt){
    if(idx == N) {
        D[N][0] = 1;
        return 0;
    }

    int &ret = D[idx][cnt];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = -1; i <= 1; i++){
        if(cnt + i < 1) continue;
        int next = idx + cnt + i;
        if(!chk[next] && next <= N)
            ret = min(ret, solve(next, cnt + i) + 1);
    }

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N >> M;
    while(M--){
        int num;
        cin >> num;
        chk[num] = true;
    }

    int answer = solve(1, 0);
    if(D[N][0] == 1) cout << answer << '\n';
    else cout << -1 << '\n';
}
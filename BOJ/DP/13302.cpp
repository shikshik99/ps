#include <bits/stdc++.h>
#define MAX 101
#define INF 0x6f6f6f6f
using namespace std;

int D[MAX][MAX];
bool chk[MAX];
int day[3] = {1, 3, 5};
int fee[3] = {10, 25, 37};
int N, M;

int solve(int idx, int cnt){
    if(idx == N) return 0;
    
    int &ret = D[idx][cnt];
    if(ret != -1) return ret;
    
    if(chk[idx]) return ret = solve(idx + 1, cnt);

    ret = INF;
    for(int i = 0; i < 3; i++){
        int next = idx + day[i];
        int next_cnt = cnt + i;
        if(next <= N){
            ret = min(ret, solve(next, next_cnt) + fee[i]);
        }        
    }
    
    if(cnt >= 3) ret = min(ret, solve(idx + 1, cnt - 3));

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N >> M;
    
    int num;
    while(M--) cin >> num, chk[num - 1] = true;

    cout << (long long)solve(0, 0) * 1000 << '\n';
}
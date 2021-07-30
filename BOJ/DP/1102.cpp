#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define INF 0x6f6f6f6f
using namespace std;

int W[17][17];
int D[1 << 17];
int N, P;
string str;

int TSP(int visit){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(visit & (1 << i)) cnt++;
    }

    if(cnt >= P) return 0;

    int &ret = D[visit];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < N; i++){
        if(!(visit & (1 << i))) continue;
        for(int j = 0; j < N; j++){
            if(visit & (1 << j)) continue;
            // 비용이 0인 경우도 있다,,
            ret = min(ret, TSP(visit | (1 << j)) + W[i][j]);
        }
        
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> W[i][j];
    }

    cin >> str;

    int visit = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'Y') {
            visit |= (1 << i);
        }
    }
    cin >> P;
    
    memset(D, -1, sizeof(D));
    int ans = TSP(visit);
    if(ans == INF) cout << -1 << '\n', exit(0);
    cout << ans << '\n';
}
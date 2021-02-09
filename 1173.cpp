#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, m, M, T, R, ans = 0, cnt = 0;
    cin >> N >> m >> M >> T >> R;
    int X = m;
    while(cnt < N){
        if(ans >= 10000001) {cout << -1; return 0;}
        while(X + T <= M && cnt < N) ans++, cnt++, X += T;
        while(X + T > M && cnt < N) {ans++, X -= R;}
        if(X < m && cnt < N) X = m;
    }
    cout << ans;
}
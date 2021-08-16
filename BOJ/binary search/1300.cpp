#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, K;

bool possible(ll mid){
    ll cnt = 0;
    for(int i = 1; i <= N; i++){
        cnt += min(mid / i, (ll)N);
    }

    return cnt < K ? true : false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;

    ll lo = 0, hi = ll(N * N + 1);
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }
    cout << hi << '\n';
}
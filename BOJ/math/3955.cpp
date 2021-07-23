#include <iostream>
#define MAX 1000000000
using namespace std;
using ll = long long;

struct ret{
    ll s, t, r;
    ret() {s = 0, t = 0, r = 0;}
    ret(ll ss, ll tt, ll rr) {s = ss, t = tt, r = rr;}
};

ret ExtendedGCD(ll a, ll b){
    ll s0 = 1, t0 = 0, r0 = a;
    ll s1 = 0, t1 = 1, r1 = b;
    ll q, tmp;

    while(r1){
        q = r0 / r1;

        tmp = r0 - (q * r1);
        r0 = r1, r1 = tmp;

        tmp = s0 - (q * s1);
        s0 = s1, s1 = tmp;

        tmp = t0 - (q * t1);
        t0 = t1, t1 = tmp;
    }
    struct ret r(s0, t0, r0);
    return r;
}

int main(){
    int T;
    cin >> T;

    int K, C;
    struct ret result;
    while(T--){
        cin >> K >> C;
        result = ExtendedGCD(K, C);
        ll s = result.s, t = result.t, r = result.r;

        if(C == 1){
            if(K >= MAX) cout << "IMPOSSIBLE\n";
            else cout << K + 1 << '\n';
            continue;
        }
        else if(K == 1){
            cout << 1 << '\n';
            continue;
        }

        if(r != 1){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        if(t > MAX){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        while(t < 0) t += K;
        cout << t << '\n';
    }
}
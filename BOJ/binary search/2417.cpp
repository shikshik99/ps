#include <iostream>
#include <cmath>
using namespace std;
using ll = unsigned long long;

ll N;

bool possible(ll tmp){
    return tmp * tmp < N ? true : false;
}

int main(){
    cin >> N;
    if(!N) cout << 0 << '\n', exit(0);
    
    ll lo = 0, hi = pow(2, 32) + 1;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << hi << '\n';
}
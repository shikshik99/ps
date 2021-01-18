#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll n, m, sum;
ll l = 0, r = 0;
vector <int>v;

ll foo(){
    ll cnt = 0, mid = 0;
    while(l <= r){
        cnt = 1;
        sum = 0;
        mid = (l+r)/2;
        for(ll i = 0; i < n; i++){
            if(sum+v[i] > mid){
                cnt++; sum = 0;
            }
            sum += v[i];       
        }
        if(cnt > m) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        r += v[i];
        if(l < v[i]) l = v[i];
    }
    ll ans = foo();
    cout << ans;
}
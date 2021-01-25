#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector <ll>v;
ll N, M;

ll foo(){
    ll l = 0, r = M, mid, sum;
    while(l <= r){
        mid = (l+r)/2;
        sum = 0;
        for(int i = 0; i < N; i++){
            if(v[i] < mid) sum += v[i];
            else sum += mid;
        }
        if(sum > M) r = mid - 1;
        else l = mid + 1;
    }
    return l - 1;
}

int main(){
    ll tmp = 0, ma = 0;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {cin >> v[i]; tmp += v[i]; ma = max(v[i],ma);}
    cin >> M;
    if(M >= tmp) {cout << ma; return 0;}
    ll ans = foo();
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector <ll> v;
ll N, M;

ll get_wood(ll num){
    ll ret = 0;
    for(int i = 0; i < N; i++){
        if(v[i] > num) ret += (v[i] - num);
    }

    return ret;
}

int main(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll l = 0, r = v[N - 1], mid, ret;
    while(l <= r){
        mid = (l + r) / 2;
        ret = get_wood(mid);
        if(ret < M) r = mid - 1;
        else l = mid + 1;
    }
    
    cout << r << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector <ll>v;
int N, M;

ll foo(){
    ll l = 0, r = M * v[N-1], mid;
    while(l <= r){
        mid = (l+r)/2;
        ll sum  = 0;
        for(int i = 0; i < N; i++) sum += mid / v[i];
        if(sum >= M) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << foo();
}   
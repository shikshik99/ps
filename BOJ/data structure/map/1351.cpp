#include <iostream>
#include <map>
using namespace std;
using ll = long long;

map <ll, ll> D;
ll N, P, Q;

ll foo(ll idx){
    if(D.find(idx) != D.end()) return D[idx];

    return D[idx] = foo(idx / P) + foo(idx / Q);
}

int main(){
    D[0] = 1;
    cin >> N >> P >> Q;

    cout << foo(ll(N));
}
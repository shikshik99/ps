#include <iostream>
using namespace std;
using ll = long long;

ll A, B, C;

ll foo(ll depth){
    if(depth == 1) return A;
    ll ret;
    ret = foo(depth / 2);

    ret = (ret * ret) % C;

    if(depth % 2) ret = (ret * A) % C;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A >> B >> C;

    cout << foo(B) % C;    
}
#include <iostream>
using namespace std;
#define ll unsigned long long

ll foo(ll A, ll B, ll C){
    if(!B) return 1;
    ll tmp = foo(A, B/2, C);
    tmp = (tmp * tmp) % C;
    if(B%2) return (tmp * A) % C;
    else return tmp;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll A, B, C;
    cin >> A >> B >> C;
    ll answer = foo(A,B,C);
    cout << answer;
}

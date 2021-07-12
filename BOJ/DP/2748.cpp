#include <iostream>
#include <cstring>
using namespace std;
#define ll long long

ll D[91];

ll foo(int tmp){
    if(D[tmp] != -1) return D[tmp];

    ll &ret = D[tmp];
    ret = 0;

    ret = foo(tmp - 2) + foo(tmp - 1);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    int N;
    cin >> N;
    D[0] = 0, D[1] = 1;
    cout << foo(N);
}
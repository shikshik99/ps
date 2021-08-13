#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;
using ll = long long;

ll D[MAX];

ll foo(int N){
    ll &ret = D[N];
    if(ret != -1) return ret;

    return ret = (foo(N - 1) % MOD + foo(N - 2) % MOD) % MOD;
}

int main(){
    int N;
    cin >> N;
    memset(D, -1, sizeof(D));

    D[1] = 1, D[2] =2;

    cout << foo(N) % MOD << '\n';
}
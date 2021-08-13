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

    return ret = (2 * (foo(N - 2) % MOD) + foo(N - 1) % MOD) % MOD;
}

int main(){
    memset(D, -1, sizeof(D));
    int N;
    cin >> N;
    D[1] = 1, D[2] = 3;
    cout << foo(N) << '\n';
}
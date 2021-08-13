#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;
using ll = long long;

ll D[MAX][MAX];

ll foo(int N, int K){
    ll &ret = D[N][K];
    if(ret != -1) return ret;
    if(K == 0 || K == N) return ret = 1;

    ret = foo(N - 1, K - 1) % MOD + foo(N - 1, K);

    return ret % MOD;
}

int main(){
    memset(D, -1, sizeof(D));
    int N, K;
    cin >> N >> K;

    cout << foo(N, K) % MOD << '\n';
}
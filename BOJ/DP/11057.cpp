#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 10007
using namespace std;
using ll = long long;

ll D[MAX][10];

ll foo(int N, int digit){
    ll &ret = D[N][digit];
    if(ret != -1) return ret;

    if(N == 1) return ret = 1;

    ret = 0;
    for(int i = digit; i < 10; i++) ret += foo(N - 1, i) % MOD;

    return ret % MOD;
}

int main(){
    memset(D, -1, sizeof(D));
    int N;
    cin >> N;
    
    ll answer = 0;
    for(int i = 0; i < 10; i++){
        answer += foo(N, i) % MOD;
    }

    cout << answer % MOD << '\n';
}
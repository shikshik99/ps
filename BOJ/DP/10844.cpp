#include <iostream>
#include <cstring>
#define MAX 101
#define MOD 1000000000
using namespace std;
using ll = long long;

ll D[101][10];

ll foo(int N, int num){
    if(N == 1) return 1;

    ll &ret = D[N][num];
    if(ret != -1) return ret;
     
    ret = 0;
    if(num + 1 < 10) ret = (foo(N - 1, num + 1)) % MOD;
    if(num - 1 >= 0) ret += (foo(N - 1, num - 1)) % MOD;

    return ret % MOD;
}

int main(){
    memset(D, -1, sizeof(D));
    int N;
    cin >> N;
    ll answer = 0;
    for(int i = 1; i < 10; i++){
        answer += foo(N, i) % MOD;
    }
    cout << answer % MOD << '\n';
}
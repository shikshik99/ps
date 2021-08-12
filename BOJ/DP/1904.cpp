#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;
using ll = long long;

ll D[MAX];

ll foo(int num){
    ll &ret = D[num];
    if(ret != -1) return ret;

    return ret = foo(num - 1) % 15746 + foo(num - 2) % 15746;
}

int main(){
    memset(D, -1, sizeof(D));
    D[1] = 1, D[2] = 2;

    int N;
    cin >> N;
    cout << foo(N) % 15746 << '\n';
}
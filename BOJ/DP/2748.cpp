#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

ll D[91] = {0,};

ll foo(int num){
    ll &ret = D[num];
    if(ret != -1) return ret;

    ret = foo(num - 1) + foo(num - 2);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    D[0] =  0, D[1] = 1;
    int N; cin >> N;
    cout << foo(N);
}
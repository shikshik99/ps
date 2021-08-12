#include <iostream>
#include <cstring>
#define MAX 91
using namespace std;
using ll = long long;

ll D[MAX][2];
int N;

ll foo(int idx, int num){
    ll &ret = D[idx][num];
    if(ret != -1) return ret;

    if(idx == 0) return ret = 1;    

    ret = foo(idx - 1, 0);
    if(!num) ret += foo(idx - 1, 1);

    return ret;
}

int main(){
    cin >> N;

    memset(D, -1, sizeof(D));
    cout << foo(N - 1, 1)<< '\n';
}
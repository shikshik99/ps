#include <iostream>
#include <cstring>
using namespace std;
#define mod 1000000009

long long d[1001][1001];
int T, n, m;

int foo(int num, int cnt){
    if(!num && cnt >= 0) return 1;
    if(num < 0 || cnt < 0) return 0;
    
    long long &ret = d[num][cnt];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 1; i <= 3; i++){
        ret = (ret + foo(num - i, cnt - 1)) % mod;
    }
    
    return ret;
}

int main(){
    cin >> T;
    memset(d, -1, sizeof(d));
    while(T--){
        cin >> n >> m;
        cout << foo(n, m) << '\n';
    }
}
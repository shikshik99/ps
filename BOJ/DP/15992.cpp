#include <iostream>
#include <cstring>
using namespace std;
#define mod 1000000009

long long d[1001][1001];

int foo(int num, int cnt){
    if(!num && !cnt) return 1;
    if(num < 0 || cnt < 0) return 0;
    
    long long &ret = d[num][cnt];
    if(ret != -1) return ret;

    ret = 0;
    /*여기 까지 고정*/
    for(int i = 1; i <= 3; i++){
        ret = (ret + foo(num-i, cnt - 1)) % mod;
    }
    
    return ret; // return값 고정
}

int main(){
    memset(d, -1, sizeof(d));
    int T, n, m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        cout << foo(n, m) << '\n';
    }
}
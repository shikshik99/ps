#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, W, H, L, a = 0, b = 0;
    int ans = 0;
    cin >> N >> W >> H >> L;
    b = L;
    while(b <= H){
        if(a+L > W) a = L, b += L;
        else a += L;
        if(b > H) break;
        ans++;
    }
    cout << min(ans, N);
}
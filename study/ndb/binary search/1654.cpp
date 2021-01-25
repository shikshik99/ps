#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ui long long

vector <ui>v;
ui mi = 10000000001, K, N;

ui foo(){
    ui l = 1, r = mi, mid, cnt;
    while(l<=r){
        mid = (l+r)/2;
        cnt = 0;
        for(int i = 0; i < K; i++) cnt += (v[i]/mid);
        if(cnt < N) r = mid - 1;
        else l = mid + 1;
    }
    return l-1;
}

int main(){
    cin >> K >> N;
    v.resize(K);
    for(int i = 0; i < K; i++){cin >> v[i];}
    ui ans = foo();
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;
int N, M, ma = 0;

int foo(){
    int l = 0, r = ma, mid;
    long long sum = 0;
    while(l<=r){
        sum = 0;
        mid = (l+r)/2;
        for(int i = 0; i < N; i++){
            if(v[i] <= mid) continue;
            else sum += (v[i]-mid);
        }
        if(sum < M) r = mid - 1;
        else if (sum > M) l = mid + 1;
        else return mid;
    }
    return r;
}

int main(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++) {cin >> v[i]; ma = max(ma, v[i]);}
    sort(v.begin(), v.end());
    int ans = foo();
    cout << ans;
}
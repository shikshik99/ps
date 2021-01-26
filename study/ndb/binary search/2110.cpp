#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;
int N, C;

int foo(){
    int l = 1, r = v[N-1], mid, ans;
    while(l <= r) {
        int cnt = 1;
        int pivot = v[0];
        mid = (l+r)/2;
        for(int i = 1; i < N; i++){
            if(v[i] - pivot >= mid) { cnt++; pivot = v[i];}
        }
        if(cnt >= C) {ans = mid; l = mid + 1;}
        else r = mid - 1;
    }
    return ans;
}

int main(){
    cin >> N >> C;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << foo();
}
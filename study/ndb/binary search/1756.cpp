#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;
int N, D;

int foo(){
    int in = 0, idx = N+1, cnt, tmp;
    for(cnt = 0; cnt < D; cnt++){
        tmp = in;
        cin >> in;
        if(!idx) return 0;
        if(in <= tmp) {idx--;}
        else{
            int l = 0, r = idx-1, mid;
            while(l <= r){
                mid = (l+r)/2;
                if(v[mid] < in) {r = mid - 1;}
                else {idx = mid;l = mid + 1;}
            }
        }
    }
    return idx;
}

int main(){
    cin >> N >> D;
    v.resize(N+1);
    v[0] = 1111111111;
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] = min(v[i], v[i-1]);
        }
        int ans = foo();
        cout << ans;
}
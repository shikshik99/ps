#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector <ll> v1, v2;

int main(){
    int N;
    cin >> N;
    vector <ll> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            v1.push_back(A[i] + B[j]);
            v2.push_back(C[i] + D[j]);
        }
    }   

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll answer = 0, target;
    int idx = 0, lo, hi;
    while(idx < v1.size()){
        target = 0 - v1[idx++];
        lo = lower_bound(v2.begin(), v2.end(), target) - v2.begin();
        hi = upper_bound(v2.begin(), v2.end(), target) - v2.begin();
        answer += (hi - lo);
    }
    
    cout << answer << '\n';
}
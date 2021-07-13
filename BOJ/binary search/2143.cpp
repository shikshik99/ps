#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector <ll> A, B;
vector <ll> arr1, arr2;
int T, N, M;

void subarray(int idx, int depth, int max, ll sum, vector <ll> &tmp, vector <ll> origin){
    for(int i = idx; i < max; i++){
        sum += origin[i];
        tmp.push_back(sum);
    }
}

int main(){
    cin >> T >> N;
    arr1.resize(N);
    for(int i = 0; i < N; i++) cin >> arr1[i];
    cin >> M;
    arr2.resize(M);
    for(int i = 0; i < M; i++) cin >> arr2[i];

    for(int i = 0; i < N; i++) subarray(i, 0, N, 0, A, arr1);
    for(int i = 0; i < M; i++) subarray(i, 0, M, 0, B, arr2);
    
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    ll answer = 0, target;
    int lo, hi;
    for(int i = 0; i < A.size(); i++){
        target = T - A[i];
        lo = lower_bound(B.begin(), B.end(), target) - B.begin();
        hi = upper_bound(B.begin(), B.end(), target) - B.begin();
        answer += hi - lo;
    }
    cout << answer << '\n';
}
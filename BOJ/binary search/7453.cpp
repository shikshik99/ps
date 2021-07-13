#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector <ll> A, B, C, D;
vector <ll> v1, v2;
int N;

int main(){
    cin >> N;
    A.resize(N), B.resize(N), C.resize(N), D.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    ll sum1, sum2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sum1 = A[i] + B[j];
            sum2 = C[i] + D[j];
            v1.push_back(sum1), v2.push_back(sum2);
        }
    }

    sort(v2.begin(), v2.end());

    ll answer = 0, tmp;
    ll len = v1.size(), lo, hi;
    for(int i = 0; i < len; i++){
        tmp = 0 - v1[i];
        lo = lower_bound(v2.begin(), v2.end(), tmp) - v2.begin();
        hi = upper_bound(v2.begin(), v2.end(), tmp) - v2.begin();
        answer += (hi - lo);
    }

    cout << answer << '\n';
}
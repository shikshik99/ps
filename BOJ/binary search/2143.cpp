#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector <ll> A, B;
vector <ll> v1, v2;
int T, n, m;

int main(){
    cin >> T >> n;
    A.resize(n, 0);
    for(int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    B.resize(m, 0);
    for(int i = 0; i < m; i++) cin >> B[i];

    ll sum = 0;
    for(int i = 0; i < n; i++){
        v1.push_back(A[i]);
        sum = A[i];
        for(int j = i + 1; j < n; j++){
            sum += A[j];
            v1.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++){
        v2.push_back(B[i]);
        sum = B[i];
        for(int j = i + 1; j < m; j++){
            sum += B[j];
            v2.push_back(sum);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll target, answer = 0;
    int idx = 0, lo, hi;
    while(idx < v1.size()){
        target = T - v1[idx++];
        lo = lower_bound(v2.begin(), v2.end(), target) - v2.begin();
        hi = upper_bound(v2.begin(), v2.end(), target) - v2.begin();
        answer += (hi - lo);
    }

    cout << answer << '\n';
}
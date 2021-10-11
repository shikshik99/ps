#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

vector <int> A;
int N, M;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;

    A.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int num;
    while(M--){
        cin >> num;
        int idx = lower_bound(A.begin(), A.end(), num) - A.begin();

        if(idx == N || A[idx] != num) cout << -1 << '\n';
        else cout << idx << '\n';
    }
}
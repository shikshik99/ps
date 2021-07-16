#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    vector <int> v;

    cin >> N, v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    cin >> M;
    int hi, lo, tmp;
    while(M--){
        cin >> tmp;
        lo = lower_bound(v.begin(), v.end(), tmp) - v.begin();
        hi = upper_bound(v.begin(), v.end(), tmp) - v.begin();
        cout << hi - lo << ' ';
    }
}
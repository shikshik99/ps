#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v, v2;

int main(){
    int N, M, tmp;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> M;
    v2.resize(M);
    for(int i = 0; i < M; i++) cin >> v2[i];
    for(int i = 0; i < M; i++){
        tmp = v2[i];
        int l = 0, r = N - 1, mid;
        while(l <= r){
            mid = (l+r) / 2;
            if(v[mid] < tmp) l = mid + 1;
            else if(v[mid] > tmp) r = mid - 1;
            else break;
        }
        if(v[mid] == tmp) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}
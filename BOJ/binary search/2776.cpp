#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v, v1;
int T, N, M;

void binary_search(){
    for(int i = 0; i < M; i++){
        int l = 0, r = N - 1, mid, tmp = v1[i];
        while(l <= r){
            mid = (l+r)/2;
            if(v[mid] > tmp) r = mid - 1;
            else if (v[mid] < tmp) l = mid + 1;
            else break;
        }
        if(v[mid] == tmp) cout << 1 << '\n';
        else cout << 0 <<'\n';
    }
}

void foo(){
    for(int i = 0; i < T; i++){
        v.clear();
        cin >> N;
        v.resize(N);
        for(int j = 0; j < N; j++) cin >> v[j];
        sort(v.begin(), v.end());
        v1.clear();
        cin >> M;
        v1.resize(M);
        for(int j = 0; j < M; j++) cin >> v1[j];
        binary_search();
    }
}

int main(){
    cin >> T;
    foo();
}
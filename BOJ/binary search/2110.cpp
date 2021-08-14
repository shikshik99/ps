#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;

bool possible(int tmp){
    int cnt = 1;
    int dist = v[0];
    int idx = 0;
    while((idx = lower_bound(v.begin(), v.end(), tmp + dist) - v.begin()) < N){
        cnt++;
        dist = v[idx];
    }

    return cnt >= M ? true : false;
}

int main(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());
    
    int lo = 0, hi = v[N - 1];
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
}
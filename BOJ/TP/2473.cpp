#include <bits/stdc++.h>
#define MAX 5001
using namespace std;
using ll = long long;

ll arr[MAX];
ll result = LLONG_MAX;
int answer[3];
int N;

void solve(int idx){
    int l = idx + 1, r = N - 1;
    ll psum = 0;
    while(l < r){
        psum = arr[idx] + arr[l] + arr[r];
        if(abs(psum) < abs(result)){
            result = psum;
            answer[0] = arr[idx];
            answer[1] = arr[l];
            answer[2] = arr[r];
        }
        if(psum > 0) r--;
        else l++;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    for(int i = 0; i < N - 2; i++){
        solve(i);
    }

    for(int it : answer) cout << it << ' ';
    cout << '\n';
}
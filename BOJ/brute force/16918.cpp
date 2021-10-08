#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int arr[MAX];
bool chk[MAX];
int N, answer = 0;

void solve(int depth, int psum){
    if(depth == N - 2){
        answer = max(answer, psum);
        return;
    }

    for(int i = 1; i < N - 1; i++){
        if(chk[i]) continue;
        int l = i - 1, r = i + 1;
        while(l >= 0 && chk[l]) l--;
        while(r < N && chk[r]) r++;
        
        chk[i] = true;
        psum += (arr[l] * arr[r]);
        solve(depth + 1, psum);
        psum -= (arr[l] * arr[r]);
        chk[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    solve(0, 0);
    cout << answer << '\n';
}
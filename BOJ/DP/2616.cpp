#include <bits/stdc++.h>
#define MAX 50001
using namespace std;

int D[MAX][3];
int arr[MAX];
int N, M;

int solve(int idx, int cnt){
    if(idx >= N || cnt >= 3) return 0;

    int &ret = D[idx][cnt];
    if(ret != -1) return ret;
    
    ret = solve(idx + 1, cnt);

    int cost = 0;
    for(int i = idx; i < idx + M && i < N; i++) cost += arr[i];
    ret = max(ret, solve(idx + M, cnt + 1) + cost);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cin >> M;

    cout << solve(0, 0) << '\n';
    
}
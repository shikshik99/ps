#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 101
#define INF 0x6f6f6f6f
using namespace std;

int arr[MAX], D[MAX][10001];
int N, K;

int foo(int idx, int val){
    if(idx == N) return (val == 0 ? 0 : INF);

    int &ret = D[idx][val];

    if(ret != -1) return ret;

    ret = foo(idx + 1, val);

    if(val >= arr[idx]) ret = min(ret, foo(idx, val - arr[idx]) + 1);

    return ret;
}

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> arr[i];

    memset(D, -1, sizeof(D));
    int answer = foo(0, K);
    
    if(answer == INF) cout << -1 << '\n';
    else cout << answer << '\n';
}
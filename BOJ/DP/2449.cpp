#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x7f7f7f7f
using namespace std;

int D[201][201];
int arr[201];

int foo(int start, int end){
    if(start == end) return 0;
    int &ret = D[start][end];
    if(ret != -1) return ret;

    ret = 0;
    int ans = INF;
    for(int i = start; i < end; i++){
        int left = foo(start, i);
        int right = foo(i + 1, end);
        int cost = 0;
        if(arr[start] != arr[i + 1]) cost++;
        ans = min(ans, left + right + cost);
    }
    
    return ret = ans;
}

int main(){
    memset(D, -1, sizeof(D));
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];

    cout << foo(0, N - 1);
}
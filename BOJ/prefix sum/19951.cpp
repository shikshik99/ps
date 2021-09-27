#include <bits/stdc++.h>
#define MAX 100002
using namespace std;

int arr[MAX], sum[MAX];
int tmp[MAX];
int N, M;

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    int a, b, h;
    while(M--){
        cin >> a >> b >> h;
        sum[a] += h;
        sum[b + 1] -= h;
    }

    for(int i = 1; i <= N; i++){
        tmp[i] = sum[i] + tmp[i - 1];
    }

    for(int i = 1; i <= N; i++) cout << arr[i] + tmp[i] << ' ';
}
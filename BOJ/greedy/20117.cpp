#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int arr[MAX];
int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    int answer = 0;
    int l = 0, r = N - 1;
    while(l <= r){
        if(l == r) answer += arr[r];
        else answer += (arr[r] * 2);
        l++, r--;
    }

    cout << answer << '\n';
}
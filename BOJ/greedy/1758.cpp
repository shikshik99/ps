#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
using ll = long long;

int arr[MAX];
int N;

bool cmp(int a, int b){
    return a > b ? true : false;
}

int main(){
    cin >> N;
    for(int i = 1; i < N + 1; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1, cmp);
    
    ll answer = 0;
    for(int i = 1; i < N + 1; i++){
        int cost = arr[i] - (i - 1);
        if(cost <= 0) break;
        answer += cost;
    }

    cout << answer << '\n';
}
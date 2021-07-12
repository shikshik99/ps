#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll arr[10001];

int main(){
    ll N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> arr[i];

    ll start = 0, end = 0, answer = 0, sum = 0;
    while(end <= N){
        if(sum < M) sum += arr[end], end++;
        else sum -= arr[start], start++;
        if(sum == M) answer++;
    }

    cout << answer << '\n';
}
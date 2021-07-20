#include <iostream>
using namespace std;

int arr[10001];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    int l = 0, r = 0, sum = 0;
    int answer = 0;
    while(r <= N){
        if(sum == M) answer++;
        if(sum > M) sum -= arr[l], l++;
        else sum += arr[r], r++;
    }

    cout << answer << '\n';
}
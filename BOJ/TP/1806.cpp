#include <iostream>
using namespace std;
#define ll long long

ll arr[100001];

int main(){
    int N, S;
    cin >> N >> S;

    for(int i = 0; i < N; i++) cin >> arr[i];
    if(!S) cout << 1 << '\n', exit(0);

    ll start = 0, end = 0, answer = 0x7f7f7f7f, sum = 0;
    while(end <= N){
        if(sum < S) sum += arr[end], end++;
        else{
            answer = answer < (end - start) ? answer : (end - start);
            sum -= arr[start], start++;
        }
    }
    
    if(answer == 0x7f7f7f7f) cout << 0 << '\n';
    else cout << answer << '\n';
}
#include <iostream>
using namespace std;
#define MAX 0x6f6f6f6f
using ll = long long;

ll arr[100001];
int N, S;

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int l = 0, r = 0;
    ll sum = 0, answer = MAX;
    while(r <= N){
        if(sum < S) sum += arr[r++];
        else {
            answer = answer < (r - l) ? answer : (r - l);
            sum -= arr[l++];
        }
    }

    if(answer == MAX) cout << 0 << '\n', exit(0);
    cout << answer << '\n';
}
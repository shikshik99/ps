#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int arr[MAX], LR[MAX], RL[MAX];
int N;

int GCD(int a, int b){
    if(!b) return a;
    
    return GCD(b, a % b);
}

int max_gcd(int idx){
    if(!idx) return RL[1];
    if(idx == N - 1) return LR[N - 2];
    return GCD(LR[idx - 1], RL[idx + 1]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    LR[0] = arr[0], RL[N - 1] = arr[N - 1];
    for(int i = 1; i < N; i++){
        int ma = LR[i - 1] > arr[i] ? LR[i - 1] : arr[i];
        int mi = LR[i - 1] < arr[i] ? LR[i - 1] : arr[i];
        LR[i] = GCD(ma, mi);
    }
    for(int i = N - 2; i >= 0; i--){
        int ma = RL[i + 1] > arr[i] ? RL[i + 1] : arr[i];
        int mi = RL[i + 1] < arr[i] ? RL[i + 1] : arr[i];
        RL[i] = GCD(ma, mi);
    }

    int answer = -1, num = 0;
    for(int i = 0; i < N; i++) {
        int K = arr[i];
        int tmp = max_gcd(i);
        if(!(K % tmp)) continue;
        if(tmp > answer){
            answer = tmp, num = arr[i];
        }
    }
    if(answer == -1) cout << answer << '\n', exit(0);
    cout << answer << ' ' << num << '\n';
}
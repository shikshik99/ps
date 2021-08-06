#include <iostream>
using namespace std;

int arr[11];
int N, K, answer;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = N - 1; i >= 0; i--){
        answer += (K / arr[i]);
        K %= arr[i];
    }
    cout << answer << '\n';
}
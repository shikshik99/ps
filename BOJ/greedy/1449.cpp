#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main(){
    int N, L;
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    int tmp, idx = 0, ans = 0;
    while(idx < N){
        tmp = arr[idx] + L;
        while(idx < N && arr[idx] < tmp) idx++;
        ans++;
    }

    cout << ans << '\n';
}
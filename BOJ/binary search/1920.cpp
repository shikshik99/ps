#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    cin >> M;
    while(M--){
        int num, l = 0, r = N - 1, mid, ans = 0;
        cin >> num;
        while(l <= r){
            mid = (l + r) / 2;
            if(arr[mid] < num) l = mid + 1;
            else if(arr[mid] == num){
                ans = 1; break;
            }
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
}
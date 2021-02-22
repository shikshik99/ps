#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[1000001];
int cnt[1000001];

int main(){
    int num;
    memset(arr, 0, sizeof(arr)), memset(cnt, 9999999, sizeof(cnt));
    cin >> num;
    arr[0] = 12345678;
    arr[1] = 0, cnt[1] = 0;
    for(int i = 1; i < 1000001; i++){
        if(i * 3 <= num && cnt[i * 3] > cnt[i] + 1){
            cnt[i * 3] = cnt[i] + 1;
            arr[i * 3] = i;
        }
        if(i * 2 <= num && cnt[i * 2] > cnt[i] + 1){
            cnt[i * 2] = cnt[i] + 1;
            arr[i * 2] = i;
        }
        if(i + 1 <= num && cnt[i + 1] > cnt[i] + 1){
            cnt[i + 1] = cnt[i] + 1;
            arr[i + 1] = i;
        }
    }
    cout << cnt[num] << '\n';
    int idx = arr[num];
    cout << num << ' ';
    while(idx){
        cout << idx << ' ';
        idx = arr[idx];
    }
}
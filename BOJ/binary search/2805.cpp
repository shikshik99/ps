#include <iostream>
#define MAX 1000001
using namespace std;
using ll = long long;

int arr[MAX];
int N, M;

ll get_sum(int tmp){
    ll ret = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] > tmp) ret += (arr[i] - tmp);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int lo = 0, hi = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i], hi = hi > arr[i] ? hi : arr[i];

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        ll sum = get_sum(mid);
        if(sum >= M) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n'; 
}
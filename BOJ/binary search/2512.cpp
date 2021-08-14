#include <iostream>
#define MAX 10001
using namespace std;
using ll = long long;

int arr[MAX];
int N, M;

ll get_sum(int tmp){
    ll ret = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] <= tmp) ret += arr[i];
        else ret += tmp;
    }

    return ret; 
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tmp = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i], tmp = tmp > arr[i] ? tmp : arr[i];
    cin >> M;

    ll sum = get_sum(tmp);
    
    if(sum <= M) cout << tmp << '\n', exit(0);
    
    int lo = 0, hi = M;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        sum = get_sum(mid);
        if(sum > M) hi = mid;
        else lo = mid;
    }

    cout << lo << '\n';
}
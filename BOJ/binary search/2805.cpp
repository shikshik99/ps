#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M;
ll arr[1000001];

ll wood(ll tmp){
    ll ret = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] > tmp)
            ret += (arr[i] - tmp);
    }
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    ll l = 0, r = arr[N - 1], mid, tmp;
    while(l <= r){
        mid = (l + r) / 2;
        tmp = wood(mid);
        if(tmp < M) r = mid - 1;
        else l = mid + 1;
    }
    cout << r << '\n';
}
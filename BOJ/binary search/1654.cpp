#include <iostream>
#include <cmath>
#define MAX 10001
#define HI pow(2, 31)
using namespace std;
using ll = long long;

ll arr[MAX];
int N, M;

bool possible(ll tmp){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += (arr[i] / tmp);
    }

    return cnt >= M ? true : false;
}

int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) cin >> arr[i];

    ll lo = 0, hi = HI;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
}

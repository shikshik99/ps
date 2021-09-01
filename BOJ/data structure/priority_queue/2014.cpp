#include <iostream>
#include <queue>
#include <set>
#define MAX 101
using namespace std;
using ll = long long;

priority_queue <ll, vector<ll>, greater<ll>> pq;
set <ll> S;
int arr[MAX];
int N, K;

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> arr[i], pq.push(arr[i]), S.insert(arr[i]);

    ll ma = arr[N - 1];
    ll num;
    while(K){
        num = pq.top();
        pq.pop();
        for(int i = 0; i < N; i++){
            ll tmp = num * arr[i];
            if(pq.size() > K && tmp > ma) continue;
            if(S.find(tmp) != S.end()) continue;
            ma = tmp > ma ? tmp : ma;
            pq.push(tmp), S.insert(tmp);
        }
        K--;
    }

    cout << num << '\n';
}
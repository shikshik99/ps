#include <iostream>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

struct cmp{
    bool operator() (ll a, ll b){
        return a > b ? true : false;
    }
};

priority_queue <ll, vector<ll>, cmp> pq;
set <ll> s;
ll arr[101];
int K, N;

ll ans(){
    ll ret = 0, ma = arr[K - 1];
    while(N){
        ret = pq.top(), pq.pop();
        for(int i = 0; i < K; i++) {
            ll tmp = ret * arr[i];
            if(pq.size() > N && tmp > ma) continue;
            if(s.find(tmp) != s.end()) continue;
            ma = ma > tmp ? ma : tmp;
            pq.push(tmp);
            s.insert(tmp);
        }
        N--;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> K >> N;
    for(int i = 0; i < K; i++) cin >> arr[i], pq.push(arr[i]), s.insert(arr[i]);
    cout << ans() << '\n';
}
#include <iostream>
#include <queue>
#include <set>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

struct compare{
    bool operator()(pii a, pii b){
        if(a.first < b.first) return true;
        else if(a.first == b.first){
            if(a.second > b.second) return true;
        }

        return false;
    }
};

priority_queue <pii> pq;
multiset <int> s;

int main(){
    int N, K;
    cin >> N >> K;
    
    int weight;
    pii tmp;
    for(int i = 0; i < N; i++) cin >> tmp.first >> tmp.second, pq.push({tmp.second, tmp.first});
    for(int i = 0; i < K; i++) cin >> weight, s.insert(weight);

    ll answer = 0;
    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        auto it = s.lower_bound(tmp.second);
        if(it != s.end()) s.erase(it), answer += tmp.first;
    }

    cout << answer << '\n';
}
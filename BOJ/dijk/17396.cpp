#include <bits/stdc++.h>
#define MAX 100001
#define INF LLONG_MAX
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector <pii> graph[MAX];
bool chk[MAX];
ll dist[MAX];
int N, M;

struct cmp{
    bool operator()(pii a, pii b){
        return a.second > b.second ? true : false;
    }
};

void dijk(){
    priority_queue <pii, vector<pii>, cmp> pq;
    pq.push({0, 0});
    dist[0] = 0;
    
    while(!pq.empty()){
        ll curr = pq.top().first;
        ll cost = pq.top().second;
        pq.pop();
        if(cost > dist[curr]) continue;
        for(pii it : graph[curr]){
            ll next = it.first;
            ll next_cost = cost + it.second;
            if(next_cost >= dist[next]) continue;
            if(chk[next]) continue;
            dist[next] = next_cost;
            pq.push({next, next_cost});
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> chk[i];

    int u, v, cost;
    while(M--){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
    fill(dist, dist + N, INF);
    chk[N - 1] = false;
    if(chk[0]) cout << -1 << '\n', exit(0);
    dijk();
    cout << (dist[N - 1] == INF ? -1 : dist[N - 1]) << '\n';
}
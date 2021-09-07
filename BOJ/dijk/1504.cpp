#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 801
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;

bool chk[MAX] = {false, };
int dist[MAX];
vector <pii> graph[MAX];
int N, E, a, b;

struct cmp{
    bool operator()(pii a, pii b){
        return a.first < b.first ? true : false;
    }
};

void shortest_path(int start){
    priority_queue <pii, vector<pii>, cmp> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && chk[curr]);

        for(pii it : graph[curr]){
            int next = it.first;
            int cost = dist[curr] + it.second;
            if(cost >= dist[next]) continue;
            dist[next] = cost;
            pq.push({cost, next});
        }
    }
}

int main(){
    cin >> N >> E;

    int u, v, cost;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    cin >> a >> b;

    fill(chk, chk + MAX, false);
    fill(dist, dist + MAX, INF);
    shortest_path(1);

    int path_a = dist[a], path_b = dist[b];
    
    fill(chk, chk + MAX, false);
    fill(dist, dist + MAX, INF);
    shortest_path(a);

    if(path_a == INF || dist[b] == INF) path_a = INF;
    else path_a += dist[b];
    if(path_b == INF ||dist[N] == INF) path_b = INF;
    else path_b += dist[N];
    
    fill(chk, chk + MAX, false);
    fill(dist, dist + MAX, INF);
    shortest_path(b);

    if(path_a == INF || dist[N] == INF) path_a = INF;
    else path_a += dist[N];
    if(path_b == INF || dist[a] == INF) path_b = INF;
    else path_b += dist[a];

    int answer = min(path_a, path_b);
    if(answer == INF) cout << -1 << '\n';
    else cout << min(path_a, path_b) << '\n';
}
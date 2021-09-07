#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
#define INF 0x7f7f7f7f
using namespace std;
using pii = pair<int, int>;

vector <pii> graph[MAX];
int dist[MAX];
int pre[MAX];
int N, M;

struct cmp{
    bool operator()(pii a, pii b){
        return a.first > b.first ? true : false;
    }
};

void dijkstra(int start){
    priority_queue <pii, vector<pii>, cmp> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int currcost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(currcost > dist[curr]) continue;

        for(pii it : graph[curr]){
            int next = it.first;
            int cost = currcost + it.second;
            if(cost >= dist[next]) continue;
            pre[next] = curr;
            dist[next] = cost;
            pq.push({cost, next});
        }
    }
}

int main(){
    memset(dist, INF, sizeof(dist));
    cin >> N >> M;
    int u, v, cost;

    while(M--){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    dijkstra(1);
    cout << N - 1 << '\n';
    for(int i = 2; i <= N; i++){
        cout << pre[i] << ' ' << i << '\n';
    }
}
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;

bool chk[MAX];
int dist[MAX];
vector <pii> graph[MAX];
int V, E, start;

struct cmp{
    bool operator()(pii a, pii b){
        return a.first > b.first ? true : false;
    }
};

void dijkstra(int s){
    priority_queue <pii, vector<pii>, cmp> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && chk[curr]);

        chk[curr] = true;

        for(pii it : graph[curr]){
            int next = it.first;
            int cost = it.second + dist[curr];
            if(cost >= dist[next]) continue;
            dist[next] = cost;
            pq.push({cost, next});
        }
    }
}

int main(){
    fill(dist, dist + MAX, INF);
    cin >> V >> E >> start;
    start--;
    dist[start] = 0;

    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }

    dijkstra(start);

    for(int i = 0; i < V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

}
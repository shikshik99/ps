#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 0x6f6f6f6f
#define MAX 20001
using namespace std;
using pii = pair<int, int>;

struct cmp{
    bool operator()(pii a, pii b){
        return a.second > b.second ? true : false;
    }
};

vector <pii> graph[MAX];
int D[MAX];

void Dijkstra(int start){
    D[start] = 0;
    priority_queue <pii, vector<pii>, cmp> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        int len = graph[node].size();
        for(int i = 0; i < len; i++){
            int tmp = graph[node][i].first;
            int next_cost = graph[node][i].second + cost;
            if(D[tmp] > next_cost){
                pq.push({tmp, next_cost});
                D[tmp] = next_cost;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int V, E;
    cin >> V >> E;
    int start;
    cin >> start;

    memset(D, INF, sizeof(D));
    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    Dijkstra(start);

    for(int i = 1; i <= V; i++){
        if(D[i] == INF) cout << "INF\n";
        else cout << D[i] << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;

vector <pii> graph[MAX];
int dist[MAX];
int N, M, X;

struct cmp{
    bool operator()(pii a, pii b){
        return a.first > b.first ? true : false;
    }
};

int shortest_path(int start, int end){
    priority_queue <pii, vector<pii>, cmp> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int curcost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(curcost > dist[curr]) continue;

        for(pii it : graph[curr]){
            int next = it.first;
            int cost = dist[curr] + it.second;
            if(cost >= dist[next]) continue;
            dist[next] = cost;
            pq.push({cost, next});
        }
    }

    return dist[end];
}

int main(){
    cin >> N >> M >> X;

    int u, v, cost;
    while(M--){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }    

    int answer = 0;
    for(int i = 1; i <= N; i++){
        fill(dist, dist + MAX, INF);
        int tmp = shortest_path(i, X);
        fill(dist, dist + MAX, INF);
        tmp += shortest_path(X, i);
        answer = max(answer, tmp);
    }
    
    cout << answer << '\n';
}
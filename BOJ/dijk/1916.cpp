#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define INF 0x6f6f6f6f

vector <pii> weight[20001];

int foo(int start, int N, int end){
    long long cost, now, next, next_cost;
    priority_queue <pii> pq;
    vector <int> dist;
    dist.resize(N+1, INF);
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        cost = -pq.top().first;
        now = pq.top().second;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto it : weight[now]){
            next_cost = cost + it.second;
            next = it.first;
            if(dist[next] > next_cost) {
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
    return dist[end];
}

int main(){
    int N, M, idx, dest, we, start, end;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) cin >> idx >> dest >> we, weight[idx].push_back({dest, we});
    cin >> start >> end;
    
    cout << foo(start, N, end);
}
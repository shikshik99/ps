#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair <int, int>
#define INF 0x6f6f6f6f

vector <vector<pii>> weight;
vector <int> D;
priority_queue <pii> pq;

void foo(int start){
    D[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int now = pq.top().second;
        int now_cost = -pq.top().first;
        pq.pop();
        if(D[now] < now_cost) continue;
        for(auto it : weight[now]){
            int next_cost = it.second + now_cost;
            int next = it.first;
            if(D[next] > next_cost){
                D[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}

int main(){
    int N, M, start, u, v, w;
    cin >> N >> M >> start;
    D.resize(N+1, INF), weight.resize(N + 1);
    for(int i = 0; i < M; i++) cin >> u >> v >> w, weight[u].push_back({v, w});
    foo(start);
    for(int i = 1; i < D.size(); i++){
        if(D[i] == INF) cout << "INF\n";
        else cout << D[i] << '\n';
    }
}
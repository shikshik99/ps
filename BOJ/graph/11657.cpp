#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x7f7f7f7f;

vector <pii> graph[MAX];
ll dist[MAX];
int N, M;

int main(){
    cin >> N >> M;
    fill(dist, dist + N + 1, INF);

    int A, B, C;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
    }

    dist[1] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 1; j <= N; j++){
            if(dist[j] == INF) continue;
            for(auto it : graph[j]){
                int next = it.first, cost = it.second;
                if(dist[j] + cost < dist[next]){
                    if(i == N - 1) cout << -1 << '\n', exit(0);
                    dist[next] = dist[j] + cost;
                }
            }
        }
    }

    for(int i = 2; i <= N; i++){
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';    
    }
}
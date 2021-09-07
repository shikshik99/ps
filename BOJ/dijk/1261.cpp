#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 101
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[MAX][MAX], board[MAX][MAX];
int N, M;

struct cmp{
    bool operator()(pair<int, pii> a, pair<int, pii> b){
        return a.first > b.first ? true : false;
    }
};

int dijkstra(){
    priority_queue<pair<int, pii>, vector<pair<int,pii>>, cmp> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while(!pq.empty()){
        int currcost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(currcost > dist[x][y]) continue;

        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
            int cost = currcost + board[dx][dy];
            if(cost >= dist[dx][dy]) continue;
            pq.push({cost, {dx, dy}});
            dist[dx][dy] = cost;
        }
    }

    return dist[N - 1][M - 1];
}

int main(){
    memset(dist, INF, sizeof(dist));
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) scanf("%1d", &board[i][j]);
    }

    cout << dijkstra() << '\n';
}
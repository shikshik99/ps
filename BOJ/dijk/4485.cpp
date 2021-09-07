#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 126
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool chk[MAX][MAX];
int dist[MAX][MAX], board[MAX][MAX];
int N;

struct cmp{
    bool operator()(pair<int, pii> a, pair<int, pii> b){
        return a.first > b.first ? true : false;
    }
};

void input(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }
}

void shortest_path(){
    priority_queue <pair<int, pii>, vector<pair<int, pii>>, cmp>pq;
    dist[0][0] = board[0][0];
    pq.push({dist[0][0], {0, 0}});

    while(!pq.empty()){
        int x, y;
        do{
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
        }while(!pq.empty() && chk[x][y]);

        for(int i = 0; i < 4; i++){
            int dx = x + arr[i][0];
            int dy = y + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy]) continue;
            int cost = dist[x][y] + board[dx][dy];
            if(cost >= dist[dx][dy]) continue;
            dist[dx][dy] = cost;
            pq.push({cost, {dx, dy}});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int idx = 1;
    while(cin >> N && N){
        input();
        for(int i = 0; i < N; i++) fill(chk[i], chk[i] + N, false), fill(dist[i], dist[i] + N, INF);
        shortest_path();
        cout << "Problem " << idx++ << ": " << dist[N - 1][N - 1] << '\n';
    }  
}
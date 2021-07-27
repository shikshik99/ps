#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, MAX;
vector <vector<int>> tree;
int parent[100001][18];
int depth[100001];


void DFS(int node){
    for(auto it : tree[node]){
        if(depth[it] != -1) continue;
        depth[it] = depth[node] + 1;
        parent[it][0] = node;
        DFS(it);
    }
}

void Find_Parent(){
    for(int k = 1; k < MAX; k++){
        for(int v = 1; v <= N; v++){
            parent[v][k] = parent[parent[v][k - 1]][k - 1];
        }
    }
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v], i = 0; 
    while(diff){
        if(diff % 2 == 1) u = parent[u][i];
        diff >>= 1;
        i++;
    }

    if(u != v){
        for(int i = MAX - 1; i >= 0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }

    return u;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    MAX = ceil(log2(N));
    tree.resize(N + 1);
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));

    int u, v;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    depth[1] = 0;
    DFS(1);
    Find_Parent();
    
    cin >> M;
    while(M--){
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
}
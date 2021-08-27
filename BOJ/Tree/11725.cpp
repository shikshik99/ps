#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector <vector<int>> tree;
bool chk[MAX] = {false, };
int parent[MAX];
int N;

void BFS(){
    queue <int> q;
    q.push(1);
    chk[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : tree[curr]){
            if(chk[next]) continue;
            chk[next] = true;
            parent[next] = curr;
            q.push(next);
        }
    }
}

int main(){
    cin >> N;
    tree.resize(N + 1);
    int a, b;
    for(int i = 1; i < N; i++) cin >> a >> b, tree[a].push_back(b), tree[b].push_back(a);

    BFS();
    for(int i = 2; i <= N; i++) cout << parent[i] << '\n';
}
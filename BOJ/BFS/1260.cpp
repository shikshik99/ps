#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

vector <vector<int>> v;
bool chk[MAX] = {false, };
int N, M, start;

void DFS(int cur){
    chk[cur] = true;
    cout << cur << ' ';
    for(int it : v[cur]){
        if(!chk[it]) DFS(it);
    }
}

void BFS(int cur){
    memset(chk, false, sizeof(chk));
    chk[cur] = true;
    cout << cur << ' ';

    queue <int> q;
    q.push(cur);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int it : v[num]){
            if(chk[it]) continue;
            cout << it << ' ';
            chk[it] = true;
            q.push(it);
        }
    }
}

int main(){
    cin >> N >> M >> start;
    v.resize(N + 1);
    int a, b;
    for(int i = 0; i < M; i++) cin >> a >> b, v[a].push_back(b), v[b].push_back(a);
    for(int i = 1; i <= N; i++) sort(v[i].begin(), v[i].end());

    DFS(start);
    cout << '\n';
    BFS(start);
    cout << '\n';
}
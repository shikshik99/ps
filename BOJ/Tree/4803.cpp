#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 501
using namespace std;

bool chk[MAX];
vector <vector<int>> v;
int N = -1, M = -1, cnt;

int BFS(int idx){
    int vertex = 1, edge = 0;
    queue<int> q;
    q.push(idx);
    chk[idx] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : v[curr]){
            edge++;
            if(chk[next]) continue;
            chk[next] = true;
            q.push(next);
            vertex++;
        }
    }
    edge /= 2;
    return (vertex - 1 == edge ? 1 : 0);
}

void BFS_ALL(){
    for(int i = 1; i <= N; i++){
        if(!chk[i]) cnt += BFS(i);
    }
}

int main(){
    int idx = 0;
    while((cin >> N >> M) && (N || M)){
        v.clear();
        cnt = 0, idx += 1;
        memset(chk, false, sizeof(chk));
        v.resize(N + 1);
        int a, b;
        for(int i = 0; i < M; i++) cin >> a >> b, v[a].push_back(b), v[b].push_back(a);
        BFS_ALL();
        cout << "Case " << idx << ": ";
        if(!cnt) cout << "No trees.\n";
        if(cnt == 1) cout << "There is one tree.\n";
        if(cnt > 1) cout << "A forest of " << cnt << " trees.\n";
    }
}
#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

vector <vector<int>> graph;
bool chk[MAX] = {false, };
int dist[MAX] = {0, };
int N, M;

int BFS(){
    queue <int> q;
    q.push(1);
    chk[1] = true;
    int ret = 0;
    while(!q.empty()){
        int qsize = q.size();
        ret++;
        while(qsize--){
            int curr = q.front();
            q.pop();
            for(int next : graph[curr]){
                if(chk[next]) continue;
                chk[next] = true;
                q.push(next);
                dist[next] = ret;
            }
        }
    }
    return ret;
}

int main(){
    cin >> N >> M;
    graph.resize(N + 1);
    int a, b;
    while(M--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int answer = BFS() - 1;
    vector<int> tmp;
    for(int i = 1; i <= N; i++){
        if(dist[i] == answer) tmp.push_back(i);
    }
    
    sort(tmp.begin(), tmp.end());
    cout << tmp[0] << ' ' << answer << ' ' << tmp.size() << '\n';
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <int>q;
vector <vector<int>>v;
bool chk[101];

int BFS(){
    int tmp, cnt = 0;
    chk[1] = true;
    q.push(1);
    while(!q.empty()){
        tmp = q.front(), q.pop();
        for(int i = 0; i < v[tmp].size(); i++){
            if(chk[v[tmp][i]]) continue;
            q.push(v[tmp][i]), chk[v[tmp][i]] = true, cnt++;
        }
    }
    return cnt;
}

int main(){
    int n, m, a, b; 
    cin >> n >> m;
    v.resize(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b, v[a].push_back(b), v[b].push_back(a);
    }
    cout << BFS();
}
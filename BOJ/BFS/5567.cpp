#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans = 0;
vector <vector<int>>v;
int chk[501];

void BFS(){
    queue <int>q;
    int tmp;
    q.push(1);
    while(!q.empty()){
        tmp = q.front(), q.pop();
        for(int i = 0; i < v[tmp].size(); i++){
            if(chk[v[tmp][i]]|| v[tmp][i] == 1) continue;
            q.push(v[tmp][i]), chk[v[tmp][i]] = chk[tmp] + 1;
            if(chk[v[tmp][i]] <= 2 && v[tmp][i] != 1) ans++;
        }
    }
}

int main(){
    int n, m, tmp;
    cin >> n >> m;
    v.resize(n + 1);
    for(int i = 0; i < m; i++){
        cin >> n >> tmp, v[n].push_back(tmp), v[tmp].push_back(n);
    }
    BFS();
    cout << ans;
}
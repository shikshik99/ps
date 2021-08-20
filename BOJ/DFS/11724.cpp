#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

vector <vector<int>> v;
bool chk[MAX];
int N, M;

void dfs(int cur){
    chk[cur] = true;
    for(int it : v[cur]){
        if(!chk[it]) dfs(it);
    }
}

int dfs_all(){
    int ret = 0;
    for(int i = 1; i <= N; i++){
        if(!chk[i]) dfs(i), ret++;
    }

    return ret;
}

int main(){
    memset(chk, false, sizeof(chk));
    cin >> N >> M;
    v.resize(N + 1);
    int a, b;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << dfs_all() << '\n';
}
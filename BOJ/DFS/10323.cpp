#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <vector<int>> v;
bool chk[2001];
int n, m, a, b;
bool fla = false;

void foo(int idx, int depth){
    if(fla) return;
    if(depth == 4) {fla = true; return;}
    if(chk[idx]) return;
    chk[idx] = true;
    for(int i = 0; i < v[idx].size(); i++){
        int next = v[idx][i];
        if(chk[next]) continue;
        foo(next, depth + 1);
    }
    chk[idx] = false;
}

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < m; i++) cin >> a >> b, v[a].push_back(b), v[b].push_back(a);
    for(int i = 0; i < n; i++){
        memset(chk, false, sizeof(chk));
        foo(i, 0);
    }
    if(fla) cout << 1;
    else cout << 0;
}
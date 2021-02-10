#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector <int>v, ans, tmp1, tmp2;
bool chk[101];
int N;

void DFS(int idx){
    if(chk[idx]) return;
    tmp1.push_back(idx);
    tmp2.push_back(v[idx]);
    chk[idx] = true;
    DFS(v[idx]);
}

void foo(){
    for(int i = 1; i < N+1; i++){
        tmp1.clear();
        tmp2.clear();
        memset(chk, false, sizeof(chk));
        DFS(i);
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        tmp1.erase((unique(tmp1.begin(),tmp1.end())), tmp1.end());
        tmp2.erase((unique(tmp2.begin(),tmp2.end())), tmp2.end());
        if(tmp1 != tmp2) continue;
        for(auto it : tmp1) ans.push_back(it);
    }
}

int main(){
    cin >> N;
    v.resize(N+1);
    for(int i = 1; i < N+1; i++)cin >> v[i];
    foo();
    sort(ans.begin(), ans.end());
    ans.erase((unique(ans.begin(),ans.end())), ans.end());
    cout << ans.size() << '\n';
    for(auto it : ans) cout << it << '\n';
}
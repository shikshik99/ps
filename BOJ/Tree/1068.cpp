#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

bool chk[MAX] = {false, };
vector <vector<int>> v;
int N, target, root;

int DFS(int idx){
    chk[idx] = true;
    int ret = 0;
    for(int next : v[idx]){
        if(chk[next]) continue;
        ret += DFS(next);
    }
    
    return ret == 0 ? 1 : ret;
}

int main(){
    cin >> N;
    v.resize(N + 1);
    int idx;
    for(int i = 0; i < N; i++){
        cin >> idx;
        if(idx == -1) root = i;
        else v[idx].push_back(i);
    }
    cin >> target;
    if(target == root) cout << 0 << '\n', exit(0);
    chk[target] = true;
    cout << DFS(root) << '\n';
}
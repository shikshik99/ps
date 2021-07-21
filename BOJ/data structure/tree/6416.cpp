#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> tree[14];
int chk[14] = {0, };
bool path[14] = {false, };
int root, root_cnt;

bool chk_node(){
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < tree[i].size(); j++){
            chk[tree[i][j]]++;
        }
    }
    
    for(int i = 0; i < 14; i++){
        if(!tree[i].empty() && !chk[i]) root_cnt++, root = i;
        if(chk[i] > 1) return false;
    }

    if(root_cnt > 1) return false;
    return true;
}

void DFS(int idx){
    if(path[idx]) return;
    path[idx] = true;
    for(int i = 0; i < tree[idx].size(); i++){
        int num = tree[idx][i];
        DFS(num);
    }
}

bool chk_path(){
    DFS(root);
    for(int i = 0; i < 14; i++){
        if(!tree[i].empty() && !path[i]) return false;
    }

    return true;
}

bool chk_empty(){
    for(int i = 0; i < 14; i++){
        if(!tree[i].empty()) return false;
    }

    return true;
}

void check_istree(int k){
    if(chk_empty()){
        cout << "Case " << k << " is a tree.\n";
        return;
    }
    if(!chk_node() || !chk_path()){
        cout << "Case " << k << " is not a tree.\n";
        return;
    }
    cout << "Case " << k << " is a tree.\n";
}

void CLEAR(){
    for(int i = 0; i < 14; i++) tree[i].clear();
    memset(chk, 0, sizeof(chk));
    memset(path, false, sizeof(path));
    root_cnt = 0;
}

int main(){
    int u, v, idx = 1;
    while(1){
        cin >> u >> v;
        if(!u && !v) check_istree(idx++), CLEAR();
        else if(u == -1 && v == -1) exit(0);
        else{
            tree[u].push_back(v);
        }
    }
}
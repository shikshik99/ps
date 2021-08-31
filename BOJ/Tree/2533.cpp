#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1000001
using namespace std;

bool chk[MAX];
int D[MAX][2];
vector <vector<int>> v, tree;
int N;

void make_tree(int curr){
    chk[curr] = true;
    for(int next : v[curr]){
        if(chk[next]) continue;
        tree[curr].push_back(next);
        make_tree(next);
    }
}

int foo(int idx, bool isEarly){
    int &ret = D[idx][isEarly];
    
    if(ret != -1) return ret;
    ret = 0;

    if(isEarly){
        for(int it : tree[idx]) { 
            ret += min(foo(it, true), foo(it, false));
        }
    }
    else{
        for(int it : tree[idx]) { 
            ret += foo(it, true);
        }
    }

    return ret += isEarly;    
}

int main(){
    cin >> N;
    v.resize(N + 1);
    tree.resize(N + 1);
    
    int a, b;
    for(int i = 0; i < N - 1; i++) cin >> a >> b, v[a].push_back(b), v[b].push_back(a);
    
    make_tree(1);
    
    int root = 1;

    memset(D, -1, sizeof(D));
    int answer = min(foo(root, true), foo(root, false));

    cout << answer << '\n';
}
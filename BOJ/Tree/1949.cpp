#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

bool chk[MAX];
int D[MAX][2];
int arr[MAX];
vector <vector<int>> v;
vector <vector<int>> tree;
int N;

int DP(int idx, bool isGood){
    int &ret = D[idx][isGood];
    if(ret != -1) return ret;

    if(isGood) ret = arr[idx];
    else ret = 0;

    for(int it : tree[idx]){
        int tmp = DP(it, false);
        if(!isGood) tmp = max(tmp, DP(it, true));
        ret += tmp;
    }

    return ret;
}

void make_tree(int root){
    chk[root] = true;
    for(int it : v[root]){
        if(chk[it]) continue;
        tree[root].push_back(it);
        make_tree(it);
    }
}

int main(){
    cin >> N;
    v.resize(N + 1);
    tree.resize(N + 1);

    for(int i = 1; i <= N; i++) cin >> arr[i];

    int a, b;
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    make_tree(1);
    
    memset(D, -1, sizeof(D));
    int answer = DP(1, true);

    memset(D, -1, sizeof(D));
    answer = max(answer, DP(1, false));

    cout << answer << '\n';
}
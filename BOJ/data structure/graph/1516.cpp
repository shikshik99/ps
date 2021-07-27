#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector <vector<int>> tree;
int D[501], inDegree[501], ret[501];
int N;

void foo(){
    queue <int> q;
    for(int i = 1; i <= N; i++){
        if(!inDegree[i]) q.push(i);
    }

    while(!q.empty()){
        int tmp = q.front();
        int len = tree[tmp].size();
        q.pop();
        for(int i = 0; i < len; i++){
            int idx = tree[tmp][i];
            inDegree[idx]--;
            ret[idx] = max(ret[idx], ret[tmp] + D[tmp]);
            if(!inDegree[idx]) q.push(idx);
        }
    }
}

int main(){
    cin >> N;
    tree.resize(N + 1);
    memset(D, -1, sizeof(D)), memset(inDegree, 0, sizeof(inDegree));
    int cost, tmp;
    for(int i = 1; i <= N; i++){
        cin >> cost, cin >> tmp;
        while(tmp != -1){
            tree[tmp].push_back(i);
            inDegree[i]++;
            cin >> tmp;
        }
        D[i] = cost;
    }

    foo();
    for(int i = 1; i <= N; i++) cout << D[i] + ret[i] << '\n';
    
}
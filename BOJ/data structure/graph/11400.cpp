#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
using pii = pair<int, int>;

vector <int> tree[MAX];
vector <pii> answer;
int arr[MAX] = {0, };
int cnt = 1;

int DFS(int node, int parent){
    arr[node] = cnt++;
    int ret = arr[node];

    int len = tree[node].size();
    for(int i = 0; i < len; i++){
        int idx = tree[node][i];
        if(idx == parent) continue;
        if(!arr[idx]) {
            int low = DFS(idx, node);
            if(low > arr[node]) answer.push_back({min(node, idx), max(node, idx)});
            ret = min(ret, low);
        }
        else ret = min(ret, arr[idx]);
    }

    return ret;
}

int main(){
    int V, E;
    cin >> V >> E;
    int A, B;
    for(int i = 0; i < E; i++){
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    DFS(1, 0);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    cout << answer.size() << '\n';
    for(auto it : answer) cout << it.first << ' ' << it.second << '\n';
}
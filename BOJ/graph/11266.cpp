#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

vector <int> tree[MAX];
bool cut[MAX] = {false, };
int arr[MAX] = {0,};
int cnt = 1;

int DFS(int num, bool R){
    arr[num] = cnt++;
    int ret = arr[num], child = 0;
    int len = tree[num].size();
    for(int i = 0; i < len; i++){
        int idx = tree[num][i];
        if(!arr[idx]){
            int low = DFS(idx, false);
            ret = min(ret, low);
            if(!R && low >= arr[num]) cut[num] = true;
            child++;
        }  
        else{
            ret = min(ret, arr[idx]);
        }
    }
    
    if(R && child >= 2) cut[num] = true;
    return ret;
}

int main(){
    int V, E;
    cin >> V >> E;
    int a, b;
    for(int i = 0; i < E; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i = 1; i <= V; i++){
        if(!arr[i]) DFS(i, true);
    }

    int answer = 0;
    for(int i = 1;i <= V; i++){
        if(cut[i]) answer++;
    }

    cout << answer << '\n';
    for(int i = 1;i <= V; i++){
        if(cut[i]) cout << i << ' ';
    }
}
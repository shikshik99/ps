#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[32001] = {0, };
vector <vector<int>> v;
queue <int> q;
int N, M;

void find_zeroDegree(){
    for(int i = 1; i <= N; i++){
        if(!arr[i]) q.push(i), arr[i] = -1;
    }
}

void foo(){
    find_zeroDegree();
    while(!q.empty()){
        int idx = q.front(); q.pop();
        int len = v[idx].size();
        for(int i = 0; i < len; i++){
            arr[v[idx][i]]--;
        }
        cout << idx << ' ';
        find_zeroDegree();
    }
}

int main(){
    cin >> N >> M;
    v.resize(N + 1);
    
    int idx, tmp;
    while(M--) cin >> idx >> tmp, v[idx].push_back(tmp), arr[tmp]++;
    
    foo();
}
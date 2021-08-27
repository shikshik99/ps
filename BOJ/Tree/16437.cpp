#include <iostream>
#include <vector>
#define MAX 123457
using namespace std;
using ll = long long;
using pci = pair <char, int>;

pci stat[MAX];
bool chk[MAX] = {false, };
vector <vector<int>> v;
int N;

ll DFS(int idx){
    chk[idx] = true;
    ll sheep = 0;
    for(int next : v[idx]){
        if(chk[next]) continue;
        sheep += DFS(next);
    }
    if(idx == 1) return sheep;
    if(stat[idx].first == 'W') sheep -= stat[idx].second;
    else sheep += stat[idx].second;
    
    return sheep < 0 ? 0 : sheep;
}

int main(){
    cin >> N;
    v.resize(N + 1);
    char ch;
    int cnt, node;
    for(int i = 2; i <= N; i++){
        cin >> ch >> cnt >> node;
        stat[i].first = ch;
        stat[i].second = cnt;
        v[i].push_back(node);
        v[node].push_back(i);
    }
    
    cout << DFS(1) << '\n';
}
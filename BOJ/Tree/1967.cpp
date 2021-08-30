#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
using namespace std;
using pii = pair<int, int>;

bool chk[MAX] = {false, };
int dist[MAX];
vector <vector<pii>> v;
int N;

void find_longest(int idx, int cnt){
    chk[idx] = true;

    for(pii it : v[idx]){
        int next = it.first;
        int val = it.second;
        if(chk[next]) continue;
        dist[next] = cnt + val;
        find_longest(next, dist[next]);
    }
}

int main(){
    cin >> N;
    v.resize(N + 1);
    int a, b, val;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b >> val;
        v[a].push_back({b, val});
        v[b].push_back({a, val});
    }
    find_longest(1, 0);
    int idx = 0;
    
    val = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] > val) idx = i, val = dist[i];
    }

    memset(chk, false, sizeof(chk));
    memset(dist, 0, sizeof(dist));
    find_longest(idx, 0);
    val = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] > val) idx = i, val = dist[i];
    }
    cout << val << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;
using pii = pair<int, int>;

int P[1001];
vector <pair<int, pii>> v;
int N, M;

bool cmp(pair<int, pii> a, pair<int, pii> b){
    return a.first > b.first ? true : false;
}

int find(int a){
    if(P[a] < 0) return a;
    return P[a] = find(P[a]);
}

void merge(int a, int b){
    a = find(a); 
    b = find(b);
    if(a == b) return;
    P[b] = a;
}

int main(){
    memset(P, -1, sizeof(P));

    cin >> N >> M;
    int start, end;
    cin >> start >> end;
    int a, b, cost;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> cost;
        v.push_back({cost, {a, b}});
    }
    sort(v.begin(), v.end(), cmp);
    int idx = 0;
    while(find(start) != find(end)){
        a = v[idx].second.first;
        b = v[idx].second.second;
        cost = v[idx].first;
        idx++;
        merge(a, b);
    }

    cout << cost << '\n';
}
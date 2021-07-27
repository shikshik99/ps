#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

struct cmp{
    bool operator()(pair<int, pii> a, pair<int, pii> b){
        return a.first > b.first ? true : false;
    }
};

priority_queue <pair<int, pii>, vector<pair<int, pii>>, cmp> pq;
int arr[1001];
int N, M;

int find(int a){
    if(arr[a] == a) return a;
    return arr[a] = find(arr[a]);
}

void UNION(int a, int b){
    arr[find(a)] = find(b);
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) arr[i] = i;

    int a, b, c;
    while(M--) cin >> a >> b >> c, pq.push({c,{a,b}});
    
    int answer = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        pii tmp = pq.top().second;
        pq.pop();
        if(find(tmp.first) != find(tmp.second)) UNION(tmp.first, tmp.second), answer += cost;
    }

    cout << answer << '\n';
}
#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

priority_queue <int> pq;
queue <pii> q;

int foo(int idx){
    int cnt = 1;
    while(!q.empty()){
        while(q.front().second != pq.top()) q.push(q.front()), q.pop();
        if(q.front().first == idx) return cnt;
        q.pop(); pq.pop();
        cnt++;
    }
}

int main(){
    int T, N, M;
    cin >> T;
    while(T--){
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
        cin >> N >> M;

        int tmp;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            pq.push(tmp);
            q.push({i, tmp});
        }

        cout << foo(M)<<'\n';
    }
}
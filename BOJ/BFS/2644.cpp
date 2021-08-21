#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
using namespace std;
using pii = pair <int, int>;

vector <vector<int>> v;
queue <pii> q;
bool chk[MAX] = {0, };
int N, t1, t2, M;

int BFS(int start){
    chk[start] = true;
    q.push({start, 0});

    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        if(num == t2) return cnt - 1;
        for(int it : v[num]){
            if(!chk[it]) q.push({it, cnt}), chk[it] = true;
        }
    }
    
    return -1;
}

int main(){
    cin >> N >> t1 >> t2 >> M;

    v.resize(N + 1);

    int x, y;
    while(M--){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << BFS(t1) << '\n';
}
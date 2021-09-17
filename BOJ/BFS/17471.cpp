#include <bits/stdc++.h>
#define MAX 11
#define INF 0x6f6f6f6f
using namespace std;

int answer = INF;
vector <int> graph[MAX];
int arr[MAX];
bool chk[MAX];
int N;

bool possible(vector <int> v, bool f){
    bool tmp[MAX];
    memset(tmp, false, sizeof(tmp));

    queue <int> q;
    q.push(v[0]);
    tmp[v[0]] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : graph[curr]){
            if(tmp[next] || chk[next] != f) continue;
            tmp[next] = true;
            q.push(next);
        }
    }
    
    for(int it : v){
        if(!tmp[it]) return false;
    }

    return true;
}

int solve(){
    int ret = 0;
    vector <int> A, B;
    for(int i = 1; i <= N; i++){
        if(chk[i]) A.push_back(i);
        else B.push_back(i);
    }

    if(A.empty() || B.empty()) return -1;
    if(!possible(A, true) || !possible(B, false)) return -1;
    
    int numA = 0, numB = 0;
    for(int it : A) numA += arr[it];
    for(int it : B) numB += arr[it];
    
    return abs(numA - numB);
}

void combination(int idx, int depth){
    if(idx == N) return ;
    int num = solve();
    if(num != -1) answer = min(answer, num);
    
    for(int i = idx; i <= N; i++){
        chk[i] = true;
        combination(i + 1, depth + 1);
        chk[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    int cnt;
    for(int i = 1; i <= N; i++){
        cin >> cnt;
        int v;
        while(cnt--){
            cin >> v;
            graph[i].push_back(v);
        }
    }

    combination(1, 0);

    cout << (answer == INF ? -1 : answer) << '\n';
}
#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int graph[MAX];
bool finished[MAX];
bool chk[MAX];
int N, cnt;

void dfs(int cur){
    chk[cur] = true;
    int next = graph[cur];
    
    if(!chk[next]) dfs(next);
    while(next != cur && chk[next] && !finished[next]){
        cnt++;
        next = graph[next];
    }
    if(next == cur) cnt++;
    
    finished[cur] = true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(finished, false, sizeof(finished));
        memset(chk, false, sizeof(chk));
        cnt = 0;
        cin >> N;
        for(int i = 1; i <= N; i++) cin >> graph[i];
        for(int i = 1; i <= N; i++){
            if(!chk[i]) dfs(i);
        }

        cout << N - cnt << '\n';
    }
}
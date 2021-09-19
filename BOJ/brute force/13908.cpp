#include <bits/stdc++.h>
using namespace std;

int N, M;
int chk[10] = {0, };
int num[7];

int dfs(int depth){
    if(depth == N){
        for(int i = 0; i < M; i++){
            if(!chk[num[i]]) return 0;
        }
        return 1;
    }

    int ret = 0;
    for(int i = 0; i < 10; i++){
        chk[i]++;
        ret += dfs(depth + 1);
        chk[i]--;
    }

    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> num[i];
    
    cout << dfs(0) << '\n';
}
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 10001
using namespace std;

bool chk[MAX] = {false, };
int P[MAX], money[MAX], setmoney[MAX];
int N, M, K;

int find(int a){
    if(P[a] < 0) return a;
    return P[a] = find(P[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    P[a] = b;
    setmoney[b] = min(setmoney[a], setmoney[b]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    memset(P, -1, sizeof(P));
    for(int i = 1; i <= N; i++) cin >> money[i], setmoney[i] = money[i];
    
    int a, b;
    while(M--){
        cin >> a >> b;
        merge(a, b);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        int parent = find(i);
        answer += setmoney[parent];
        for(int j = i + 1; j <= N; j++){
            if(chk[j]) continue;
            if(parent != find(j)) continue;
            chk[j] = true;
        }
    }
    
    if(answer > K) cout << "Oh no\n";
    else cout << answer << '\n';
}
#include <bits/stdc++.h>
#define MAX 300001
using namespace std;

int uf[MAX];
int N;

int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    uf[b] = a;
}

int main(){
    cin >> N;
    int u, v;
    memset(uf, -1, sizeof(uf));
    for(int i = 0; i < N - 2; i++){
        cin >> u >> v;
        merge(u, v);
    }
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            int a = find(i);
            int b = find(j);
            if(a == b) continue;
            cout << i << ' ' << j << '\n';
            exit(0);
        }
    }
}
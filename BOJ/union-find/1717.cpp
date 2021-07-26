#include <iostream>
#define MAX 1000001
using namespace std;

int parent[MAX];

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void UNION(int a, int b){
    parent[find(a)] = find(b);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i <= N; i++) parent[i] = i;

    int cmd, a, b;
    while(M--){
        cin >> cmd >> a >> b;
        if(!cmd) UNION(a, b);
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
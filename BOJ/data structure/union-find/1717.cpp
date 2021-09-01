#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;

int parent[MAX];
int N, M;

int find(int a){
    if(parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(parent, -1, sizeof(parent));
    cin >> N >> M;
    int cmd, a, b;
    while(M--){
        cin >> cmd >> a >> b;
        if(cmd){
            int finda = find(a);
            int findb = find(b);
            if(finda == findb) cout << "YES\n";
            else cout << "NO\n";
        }
        else merge(a, b);
    }
}
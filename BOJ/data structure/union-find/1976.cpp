#include <iostream>
#include <cstring>
#define MAX 201
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

    int num;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num;
            if(num) merge(i, j);        
        }
    }

    cin >> num, M--;
    int ans = find(num);
    while(M--){
        cin >> num;
        if(find(num) != ans) cout << "NO\n", exit(0);
    }
    
    cout << "YES\n";
}
#include <iostream>
using namespace std;

int arr[201];

int find(int a){
    if(arr[a] == a) return a;
    return arr[a] = find(arr[a]);
}

void UNION(int a, int b){
    arr[find(a)] = find(b);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) arr[i] = i;

    int tmp;
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= n; j++){
            cin >> tmp;
            if(tmp) UNION(i, j);
        }
    }

    cin >> tmp;
    int idx = find(tmp); m--;
    while(m--){
        cin >> tmp;
        if(idx != find(tmp)) cout << "NO\n", exit(0);
    }

    cout << "YES\n";
}
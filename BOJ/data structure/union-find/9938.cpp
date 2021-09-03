#include <iostream>
#include <cstring>
#define MAX 300001
using namespace std;

int uf[MAX];
bool chk[MAX];
int N, L;

int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    uf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(uf, -1, sizeof(uf));
    memset(chk, false, sizeof(chk));
    cin >> N >> L;
    int a, b;
    
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        a--, b--;
        if(!chk[a]){
            chk[a] = true;
            merge(a, b);
            cout << "LADICA\n";
        }
        else if(!chk[b]){
            chk[b] = true;
            merge(b, a);
            cout << "LADICA\n";
        }
        else if(!chk[find(a)]){
            chk[find(a)] = true;
            merge(a, b);
            cout << "LADICA\n";
        }
        else if(!chk[find(b)]){
            chk[find(b)] = true;
            merge(b, a);
            cout << "LADICA\n";
        }
        else cout << "SMECE\n";
    }
}
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map <string, string>m;
vector <string>v;
string a, b;
int N, M;

void foo(){
    for(int i = 0; i < M; i++) cout << m[v[i]] << '\n';
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        m[a] = b;
    }
    v.resize(M);
    for(int i = 0; i < M; i++) cin >> v[i];
    foo();
}
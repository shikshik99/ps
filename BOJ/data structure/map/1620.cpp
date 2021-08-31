#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, string> m;
int N, M;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    string str;
    for(int i = 1; i <= N; i++){
        cin >> str;
        m[str] = to_string(i);
        m[to_string(i)] = str;
    }

    while(M--){
        cin >> str;
        cout << m[str] << '\n';
    }
}
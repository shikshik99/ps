#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, int>m;

int main(){
    int N, M, cnt = 0;
    string str;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> str, m[str]++;
    for(int i = 0; i < M; i++){
        cin >> str;
        if(m[str]) cnt++;
    }
    cout << cnt;
}
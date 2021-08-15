#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string S;
vector <string> v;
char D[101];
int N, len;

bool foo(int idx){
    if(idx == len) return true;

    char &ret = D[idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < N; i++){
        if(idx + v[i].length() > len) continue;
        if(v[i] == S.substr(idx, v[i].length())) ret |= foo(idx + v[i].length());
    }   

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> S >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    len = S.length();
    cout << foo(0) << '\n';
}
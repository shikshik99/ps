#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char D[101] = {false, };
vector <string> v;
string S;
int N, len;

bool foo(int idx){
    char &ret = D[idx];
    if(ret != -1) return ret;
    if(idx == len) return ret = 1;

    int tmp;
    ret = 0;
    for(int i = 0; i < N; i++){
        if(len < idx + v[i].length()) continue;
        bool f = true;
        tmp = idx;
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] != S[tmp]) f = false;
            tmp++;
        }
        if(f) ret |= foo(tmp);
    }
    

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> S >> N;
    len = S.length();
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << foo(0) << '\n';
}
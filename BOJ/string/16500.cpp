#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector <string>v;
string A;
int d[101];

bool foo(int idx){
    int &ret = d[idx];

    if(idx == A.size()) return true;
    if(ret != -1) return ret;

    ret = 0;

    for(auto it : v){
        if(it.size() + idx <= A.size() && A.substr(idx, it.size()) == it) ret += foo(idx + it.length());
    }

    return ret;
}

int main(){
    int N;
    cin >> A >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    memset(d, -1, sizeof(d));

    cout << foo(0);
}
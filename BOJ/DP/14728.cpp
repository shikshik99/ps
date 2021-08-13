#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int D[101][10001];
vector <pii> v;
int N, T;

int foo(int num, int t){
    if(num == N) return 0;
    if(!t) return 0;
    
    int &ret = D[num][t];
    if(ret != -1) return ret;

    ret = foo(num + 1, t);
    if(t - v[num].first >= 0) ret = max(ret, foo(num + 1, t - v[num].first) + v[num].second);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N >> T;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

    cout << foo(0, T);
}
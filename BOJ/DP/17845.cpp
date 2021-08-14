#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

pii v[1001];
int D[1001][10001];
int N, M;

int foo(int idx, int val){
    if(idx == N || !val) return 0;

    int &ret = D[idx][val];
    if(ret != -1) return ret;

    ret = foo(idx + 1, val);
    if(val - v[idx].second >= 0) ret = max(ret, foo(idx + 1, val - v[idx].second) + v[idx].first);

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> M >> N;

    int a, b;
    for(int i = 0; i < N; i++) cin >> a >> b, v[i] = {a, b};

    memset(D, -1, sizeof(D));
    cout << foo(0, M) << '\n';
}
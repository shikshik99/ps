#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector <pii> v;

ll D[MAX][100001];
int N, K;

ll foo(int num, int weight){
    if(num == N) return 0;
    if(!weight) return 0;
    
    ll &ret = D[num][weight];
    if(ret != -1) return ret;

    ret = foo(num + 1, weight);
    if(weight - v[num].first >= 0) ret = max(ret, foo(num + 1, weight - v[num].first) + v[num].second);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N >> K;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

    cout << foo(0, K) << '\n';
}
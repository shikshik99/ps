#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector <pii> v;
int D[10001];
int N, M;


int foo(int val){
    int &ret = D[val];
    if(ret != -1) return ret;

    for(int i = 0; i < N; i++){
        if(val - v[i].second >= 0){
            ret = max(ret, foo(val - v[i].second) + v[i].first);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double tmp;

    cin >> N >> tmp;
    while(N != 0 && tmp != 0.00){
        v.clear();
        M = int(tmp * 100 + 0.5);
        int a;
        for(int i = 0; i < N; i++) cin >> a >> tmp, v.push_back({a, int(tmp * 100 + 0.5)});
        memset(D, -1, sizeof(D));
        cout << foo(M) + 1 << '\n';
        cin >> N >> tmp;
    }
}
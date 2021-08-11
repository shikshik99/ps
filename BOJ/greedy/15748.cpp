#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair <int, int>;
using ll = long long;

vector <pii> v;
int L, N, speed_1, speed_2;
int position;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first > b.first ? true : false;
    return a.second > b.second ? true : false;
}

int main(){
    cin >> L >> N >> speed_1 >> speed_2;

    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);

    ll answer = 0;
    for(int i = 0; i < N; i++){
        ll pos = v[i].first;
        ll tasty = v[i].second;
        if(pos <= position) continue;
        ll dist = pos - position;
        answer += ((dist * speed_1 - dist * speed_2) * tasty);
        position = pos;
    }

    cout << answer << '\n';
}
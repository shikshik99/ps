#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair <int, int>;
using ll = long long;

vector <pii> v;
ll length, width, height;
int N;

bool cmp(pii a, pii b){
    return a.first > b.first ? true : false;
}

int main(){
    ll answer = 0, before = 0;
    
    cin >> length >> width >> height >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++){
        ll len = v[i].first;
        ll count = v[i].second;
        before <<= 3;
        ll cnt = (length >> len) * (width >> len) * (height >> len) - before;
        cnt = min(cnt, count);
        before += cnt, answer += cnt;
    }

    if(before != length * width * height) cout << -1 << '\n', exit(0);
    cout << answer << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector <pii> v;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first ? true : false;
    return a.second < b.second ? true : false;
}

int main(){
    int N;
    cin >> N;
    v.resize(N);
    for(int i = 0 ; i < N ; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    int idx = 1, answer = 1, tmp = v[0].second;
    while(idx < N){
        if(v[idx].first >= tmp) tmp = v[idx].second, answer++;
        idx++;
    }
    cout << answer << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
using pii = pair <int, int>;

bool days[MAX];
vector <pii> v;
int N;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first > b.first ? true : false;
    return a.second > b.second ? true : false;
}

bool chk_possible(int idx){
    pii tmp = v[idx];
    for(int i = tmp.first; i >= 1; i--){
        if(!days[i]) return days[i] = true;
    }

    return false;
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);

    int answer = 0;
    for(int i = 0; i < N; i++){
        if(chk_possible(i)) answer += v[i].second;
    }

    cout << answer << '\n';
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector <pii>v;

bool cmp(pii a, pii b){
    return a.first < b.first ? true : false;
}

int main(){
    v.resize(11);
    for(int i = 0; i < 11; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    int duration = 0, answer = 0;
    for(int i = 0; i < 11; i++){
        answer += (v[i].first + duration + v[i].second * 20);
        duration += v[i].first;
    }
    cout << answer << '\n';
}
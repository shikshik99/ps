#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first ? true : false;
    return a.second < b.second ? true : false;
}

vector <pii> v;

int main(){
    int N, a, b, answer = 1; 
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a >> b, v.push_back({a,b});
    sort(v.begin(), v.end(), cmp);
    b = v[0].second;
    for(int i = 1; i < N; i++){
        if(v[i].first >= b) b = v[i].second, answer++;
    }

    cout << answer;
}
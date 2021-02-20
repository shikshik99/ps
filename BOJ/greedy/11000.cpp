#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define pii pair<int, int>

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second ? true : false;
    return a.first < b.first ? true : false;
}

vector <pii>v;
priority_queue <int, vector<int>, greater<>> pq;

int main(){
    int N, a, b, answer = 1, size;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a >> b, v.push_back({a,b});
    sort(v.begin(), v.end(), cmp);
    pq.push(v[0].second);
    for(int i = 1; i < N; i++){
        if(pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }
    cout << pq.size();
}
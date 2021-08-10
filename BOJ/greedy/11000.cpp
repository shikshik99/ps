#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair <int, int>;

struct compa{
    bool operator()(int a, int b){
        return a > b ? true : false;
    }
};

priority_queue <int, vector<int>, compa> pq;
vector <pii> v;
int N;

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second ? true : false;
    return a.first < b.first ? true : false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    
    pii tmp;
    for(int i = 0; i < N; i++) cin >> tmp.first >> tmp.second, v.push_back(tmp);
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++){
        tmp = v[i];
        if (!pq.empty() && pq.top() <= tmp.first) pq.pop();
        pq.push(tmp.second);
    }

    cout << pq.size() << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <int>answer;
vector <pii>v;

bool cmp(pii a, pii b){
    return a.first < b.first ? true : false;
}

int main(){
    int N, T, cnt;
    cin >> T;
    while(T--){
        cin >> N;
        cnt = 1, v.clear(), v.resize(N);
        for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), cmp);
        int tmp = v[0].second;
        for(int i = 1; i < N; i++){
            if(v[i].second < tmp) cnt++;
            tmp = min(tmp, v[i].second);
        }
        answer.push_back(cnt);
    }
    for(auto it : answer) cout << it << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <pii>v;
vector <int>score;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first > b.first ? true : false;
    return a.second > b.second ? true : false;
}

int main(){
    int N, answer = 0, cnt;
    cin >> N;
    v.resize(N), score.resize(1001, 0);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++){
        if(score[v[i].first]){
            cnt = v[i].first;
            while(cnt){
                if(!score[cnt]) {score[cnt] = v[i].second; break;}
                cnt--;
            }
        }
        else score[v[i].first] = v[i].second;
    }
    for(auto it : score) answer += it;
    cout << answer; 
}
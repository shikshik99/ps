#include <bits/stdc++.h>
using namespace std;
using psi = pair<string, int>;
using pii = pair<int, int>;

bool cmp(psi a, psi b){
    return a.second > b.second ? true : false;
}

bool cmp2(pii a, pii b){
    if(a.second == b.second) return a.first < b.first ? true : false;
    return a.second > b.second ? true : false;
}

map <string, int> play_time;
vector <psi> genre_idx;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int len = genres.size();
    for(int i = 0; i < len; i++){
        string str = genres[i];
        play_time[str] += plays[i];
    }
    
    vector <psi> v(play_time.begin(), play_time.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto it : v) {
        string genre = it.first;
        vector <pii> tmp;
        for(int i = 0; i < len; i++){
            if(genres[i] == genre) tmp.push_back({i, plays[i]});
        }
        sort(tmp.begin(), tmp.end(), cmp2);
        answer.push_back(tmp[0].first);
        if(tmp.size() > 1) answer.push_back(tmp[1].first);
    }
    
    return answer; 
}
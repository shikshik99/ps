#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<string,int> a,pair<string,int>b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, int>m;
    
    for(int i = 0; i < genres.size(); i++) {
        if(m.count(genres[i])) m[genres[i]] += plays[i];
        else m.insert(make_pair(genres[i], plays[i]));
    }
    
    vector <pair<string, int>>v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    int best, second;
    int bestidx, secondidx, i;
    for(auto vit : v) {
        best = second = bestidx = secondidx = -123456789;
        for(i = 0; i < genres.size(); i++){
            if(genres[i] == vit.first && best == -123456789) {best = plays[i]; bestidx = i; continue;}
            if(genres[i] == vit.first && plays[i] > second){
                second = plays[i]; secondidx = i;
                if (best < second) {swap(best, second); swap(bestidx, secondidx);}
            }
        }
        if(secondidx == -123456789) answer.push_back(bestidx);
        else {answer.push_back(bestidx); answer.push_back(secondidx);}
    }
    
    return answer;
}
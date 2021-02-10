#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<int,int>a, pair<int,int>b){
    return a.first > b.first ? true : false;
    }
};

priority_queue <pair<int,int>, vector<pair<int,int>>, cmp>pq;
vector <int> ans;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, i = 0;
    sort(jobs.begin(), jobs.end());
    
    while(1){
        if(pq.empty()) {if(time < jobs[i][0]) time = jobs[i][0]; pq.push({jobs[i][1], jobs[i][0]}), i++;}
        while(i < jobs.size() && jobs[i][0] <= time) pq.push({jobs[i][1], jobs[i][0]}), i++;
        time += pq.top().first, ans.push_back(time - pq.top().second), pq.pop();
        if(i >= jobs.size()) break;
    }
    while(!pq.empty()) time += pq.top().first, ans.push_back(time - pq.top().second), pq.pop();
    
    for(auto it : ans) answer += it;
    return answer / ans.size();
}
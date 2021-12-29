#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

priority_queue <int> pq;
queue <pii> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int len = priorities.size();
    for(int i = 0; i < len; i++) pq.push(priorities[i]), q.push({i, priorities[i]});
    
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        if(tmp.second == pq.top()) {
            pq.pop(), answer++;
            if(tmp.first == location) return answer;
        }
        else q.push(tmp);
    }
    
    return answer;
}
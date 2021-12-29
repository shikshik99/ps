#include <bits/stdc++.h>
using namespace std;
using pii = pair <int, int>;

deque <pii> dq;
queue <int> q;

int solution(int bridge_length, int weight, vector<int> t) {
    int answer = 0, curr_weight = 0;
    
    int len = t.size();
    for(int i = 0; i < len; i++) q.push(t[i]);
    
    while(!q.empty() || !dq.empty()){
        if(!dq.empty() && dq.front().second >= bridge_length) {
            curr_weight -= dq.front().first;
            dq.pop_front();
        }
        if(!q.empty() && dq.size() < bridge_length && curr_weight + q.front() <= weight){
            dq.push_back({q.front(), 0});
            curr_weight += q.front();
            q.pop();
        }
        
        len = dq.size();
        for(int i = 0; i < len; i++) dq[i].second += 1;
        answer++;
    }
    
    return answer;
}
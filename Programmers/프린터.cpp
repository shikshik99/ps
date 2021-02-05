#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <pair<int,int>>q;
    priority_queue <int>pq;
    for(int i = 0; i < priorities.size(); i++){pq.push(priorities[i]); q.push(make_pair(i, priorities[i]));}
    
    pair<int,int> tmp;
    while(!q.empty()){
        if(q.front().second == pq.top() && q.front().first == location){return answer + 1;}
        else if(q.front().second == pq.top()) {q.pop(); pq.pop();answer++;}
        else {tmp = q.front(); q.pop(); q.push(tmp);}
    }
}
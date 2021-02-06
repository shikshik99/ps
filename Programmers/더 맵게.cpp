#include <string>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

priority_queue <int, vector<int>, greater<int>>pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto it : scoville) pq.push(it);
    int tmp;
    while(pq.top() < K && pq.size() > 1){
        tmp = pq.top(); pq.pop();
        tmp += pq.top()*2; pq.pop(); pq.push(tmp);
        answer++;
    }
    if(pq.top() < K) return -1;
    return answer;
}
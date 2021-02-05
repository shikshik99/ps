#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, i = 0, bridge_weight = 0;
    queue <pair<int,int>>q;
    while(1){
        if(answer - q.front().second == bridge_length){
            bridge_weight -= q.front().first; q.pop();
        }
        while(i < truck_weights.size() && bridge_weight + truck_weights[i] <= weight){
            q.push(make_pair(truck_weights[i], answer));
            bridge_weight += truck_weights[i];
            answer++; i++;
            if(answer - q.front().second == bridge_length){
                bridge_weight -= q.front().first; q.pop();
            }
        }
        if(i >= truck_weights.size() && q.empty()) break;
        answer++;
    }
    return answer + 1;
}
#include <string>
#include <queue>
#include <vector>
using namespace std;

priority_queue <int, vector<int>, less<int>> max_pq;
priority_queue <int, vector<int>, greater<int>> min_pq;

void del_min(){
    while(!max_pq.empty()) min_pq.push(max_pq.top()), max_pq.pop();
    min_pq.pop();
    while(!min_pq.empty()) max_pq.push(min_pq.top()), min_pq.pop();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int tmp;
    for(int i = 0; i < operations.size(); i++){
        if(operations[i] == "D 1" && !max_pq.empty()) {max_pq.pop(); continue;}
        else if(operations[i] == "D -1" && !max_pq.empty()) {del_min(); continue;}
        else if(operations[i][0] == 'I'){
            tmp = 0;
            if(operations[i][2] == '-') {
                for(int j = 3; j < operations[i].size(); j++) tmp = tmp * 10 - (operations[i][j] - '0');
            }
            else {
                for(int j = 2; j < operations[i].size(); j++) tmp = tmp * 10 + (operations[i][j] - '0');
            }
            max_pq.push(tmp);
        }
    }
    
    if(max_pq.empty()) answer.push_back(0), answer.push_back(0);
    else {
        answer.push_back(max_pq.top());
        while(!max_pq.empty()) min_pq.push(max_pq.top()), max_pq.pop();
        answer.push_back(min_pq.top());
    }
    return answer;
}
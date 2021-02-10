#include <string>
#include <queue>
#include <vector>

using namespace std;
queue <int> q1,q2;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> tmp, tmp2;
    for(int i = 0; i < progresses.size(); i++) {q1.push(progresses[i]); q2.push(speeds[i]);}
    
    int cnt = 0;
    while(!q1.empty() && !q2.empty()){
        if(!q1.empty() && q1.front() >= 100){
            while(!q1.empty() && q1.front() >= 100){
                q1.pop(); q2.pop();
                cnt++;
            }
            answer.push_back(cnt); cnt = 0;
            continue;
        }
        else{
            tmp.clear(); tmp2.clear();
            while(!q1.empty()){
                tmp.push_back(q1.front() + q2.front());  tmp2.push_back(q2.front());
                q1.pop(); q2.pop();
            }
            for(int i = 0; i < tmp.size(); i++) {q1.push(tmp[i]); q2.push(tmp2[i]);}
        }
    }
    return answer;
}
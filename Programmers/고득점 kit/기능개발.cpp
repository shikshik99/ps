#include <bits/stdc++.h>
using namespace std;

queue <int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int len = progresses.size();
    for(int i = 0; i < len; i++){
        int day = 100 - progresses[i], tmp = 0;
        if(day % speeds[i]) tmp = 1;
        day = (day / speeds[i]) + tmp;
        q.push(day);
    }
    
    int day = q.front();
    while(!q.empty()){
        int cnt = 0;
        while(!q.empty() && day >= q.front()){
            q.pop(), cnt++;
        }
        answer.push_back(cnt);
        day = q.front();
    }

    return answer;
}
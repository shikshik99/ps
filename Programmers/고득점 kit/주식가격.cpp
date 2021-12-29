#include <bits/stdc++.h>
using namespace std;

stack <int> s;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    
    vector<int> answer(len, 0);
    for(int i = 0; i < len; i++) {
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = len - s.top() - 1;
        s.pop();
    }
    
    return answer;
}
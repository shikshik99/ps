#include <string>
#include <vector>
#include <deque>
using namespace std;

deque <string> dq;

void init_dq(string str, int idx){
    for(int i = 0; i < dq.size(); i++){
        if(dq[i] == str) {
            dq.erase(dq.begin() + i);
            dq.push_front(str);
            break;
        }
    }
}

string foo(string str){
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(int i = 0; i < cities.size(); i++) cities[i] = foo(cities[i]);
    if(!cacheSize) return cities.size() * 5;
    for(auto it : cities){
        if(dq.empty()) {answer += 5, dq.push_front(it); continue;}
        for(int i = 0; i < dq.size(); i++){
            if(dq[i] == it) {
                init_dq(it, i), answer += 1;
            }
        }
        if(dq.front() != it && dq.size() >= cacheSize){
            dq.pop_back();
            dq.push_front(it);
            answer += 5;
        }
        else if(dq.front() != it && dq.size() < cacheSize) dq.push_front(it), answer+= 5;
    }
    return answer;
}
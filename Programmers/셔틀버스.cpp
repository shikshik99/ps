#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> v;
queue <int> q;

void foo(int idx, string str){
    string tmp = "";
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == ':') continue;
        else tmp += str[i];
    }
    v.push_back(stoi(tmp));
}

string get_time(int time){
    string str = "";
    int hour = time / 100;
    time %= 100;
    int min = time;
    if(hour == 0) str += '0', str += '0';
    else if(hour < 10 && hour > 0) str += '0', str += (hour + '0');
    else str += (hour / 10) + '0', str += (hour % 10) + '0';
    str += ':';
    if(min == 0) str += '0', str += '0';
    else if(min < 10) str += '0', str += (min + '0');
    else str += (min / 10) + '0', str += (min % 10) + '0';
    
    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    answer.resize(5, '0');
    int time = 900;
    for(int i = 0; i < timetable.size(); i++) foo(i, timetable[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) q.push(v[i]);
    
    string str;
    while(n--){
        int tmp = m;
        if(!n){
            if(q.size() < tmp){
                answer = get_time(time);
                return answer;
            }
            while(q.front() <= time && tmp > 1) q.pop(), tmp--;
            if(q.front() > time){
                answer = get_time(time);
                return answer;
            }
            else if(q.front() == time){
                time -= 1;
                if((time % 100) >= 60) time -= 40;
                answer = get_time(time);
                return answer;
            }
            else {
                time = q.front();
                time -= 1;
                if((time % 100) >= 60) time -= 40;
                answer = get_time(time);
                return answer;
            }
        }
        while(q.front() <= time && tmp){
            q.pop(); tmp--;
        }
        if(t >= 60){
            time += ((t / 60) * 100);
            time += (t % 60);
        }
        else {
            time += t;
        }
        if((time % 100) >= 60) time += 100, time -= 60;
    }
    
    return answer;
}
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int foo(int cnt, string s){
    int i = 0, ret = 0, a = 1;
    bool f = false;
    string tmp = "";
    
    while(i + cnt <= s.length()){
        if(tmp.empty()) tmp = s.substr(i, cnt);
        else{
            if(tmp != s.substr(i, cnt)){
                ret += tmp.length();
                tmp = s.substr(i, cnt);
                
                if(a > 1 && a < 10) ret += 1;
                else if(a >= 10 && a < 100) ret += 2;
                else if(a >= 100 && a < 1000) ret += 3;
                else if(a >= 1000) ret += 4;
                
                a = 1;
            }
            else a++;
        }
        i += cnt;
    }
    ret += tmp.length();
    if(a > 1 && a < 10) ret += 1;
    else if(a >= 10 && a < 100) ret += 2;
    else if(a >= 100 && a < 1000) ret += 3;
    else if(a >= 1000) ret += 4;
    
    return ret + (s.length() % cnt);
}

int solution(string s) {
    int answer = 0x7f7f7f7f, cnt = 1;
    
    while(cnt <= s.length()){
        answer = min(answer, foo(cnt, s));
        cnt++;
    }
    
    return answer;
}
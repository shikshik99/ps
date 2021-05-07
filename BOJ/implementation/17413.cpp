#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack <char>s;
    string str, answer;
    bool flag = false;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '<') {
            flag = true;
            while(!s.empty()) answer += s.top(), s.pop();
        }
        if(str[i] == '>') {flag = false; answer += str[i]; continue;}
        if(str[i] == ' '){
            if(s.empty()) answer += str[i];
            else{
                while(!s.empty()) answer += s.top(), s.pop();
                answer += ' ';
            }
            continue;
        }
        if(flag) answer += str[i];
        else if(!flag) s.push(str[i]);
    }
    while(!s.empty()) answer += s.top(), s.pop();
    cout << answer;
}
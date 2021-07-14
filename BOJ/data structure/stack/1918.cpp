#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

stack <char>s;
map <char, int>m;

int main(){
    m['('] = 3, m[')'] = 3, m['*'] = 2, m['/'] = 2, m['+'] = 1, m['-'] = 1;
    string str, answer;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z') answer += str[i];    
        else if (!s.empty()) {
            if(str[i] == ')'){
                while(!s.empty()){
                    if(s.top() == '(') { s.pop(); break;}
                    else answer += s.top(), s.pop();
                }
            }
            else if(str[i] == '(') s.push(str[i]);
            else if(m[s.top()] == m[str[i]]) {
                while(!s.empty() && m[s.top()] >= m[str[i]]) {
                    if(s.top() == '(') break;
                    answer += s.top(), s.pop();
                }
                s.push(str[i]);
            }
            else if(m[s.top()] > m[str[i]]) {
                while(!s.empty() && m[s.top()] >= m[str[i]]) {
                    if(s.top() == '(') break;
                    answer += s.top(), s.pop();
                }
                s.push(str[i]);
            }
            else s.push(str[i]);
        }
        else if(s.empty()) s.push(str[i]);
    }
    while(!s.empty()){
        if(s.top() == '(' || s.top() == ')') s.pop();
        else answer += s.top(), s.pop();
    }
    cout << answer;
}
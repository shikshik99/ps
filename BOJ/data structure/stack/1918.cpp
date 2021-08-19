#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

map <char, int> m;
stack <char> s;

int main(){
    m['+'] = 1, m['-'] = 1, m['*'] = 2, m['/'] = 2;
    string str;
    cin >> str;
    
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') {
            cout << str[i];
            continue;
        }
        if(str[i] == '(') s.push(str[i]);
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '(') cout << s.top(), s.pop();
            s.pop();
        }
        else {
            while(!s.empty() && s.top() != '(' && m[s.top()] >= m[str[i]]) cout << s.top(), s.pop();
            s.push(str[i]);
        }
    }

    while(!s.empty()) cout << s.top(), s.pop();
}
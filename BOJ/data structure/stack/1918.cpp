#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

map <char, int> m;

int main(){
    m['+'] = 1, m['-'] = 1, m['*'] = 2, m['/'] = 2;

    string str;
    cin >> str;

    stack <char> st;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
        else if(str[i] == '(') st.push(str[i]);
        else if(str[i] == ')') {
            while(!st.empty() && st.top() != '(') cout << st.top(), st.pop();
            st.pop();
        }
        else{
            if(st.empty() || st.top() == '(') st.push(str[i]);
            else {
                while(!st.empty() && st.top() != '(' && m[st.top()] >= m[str[i]]) cout << st.top(), st.pop();
                st.push(str[i]);
            }
        }
    }
    while(!st.empty()) cout << st.top(), st.pop();
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char>s;
string str;

int foo(){
    int ans = 0, tmp = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push('(');
            tmp *= 2;
        }
        else if(str[i] == '['){
            s.push('[');
            tmp *= 3;
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '(') return 0;
            if(str[i-1] == '(') ans += tmp;
            s.pop();
            tmp /= 2;
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() != '[' ) return 0;
            if(str[i-1] == '[') ans +=tmp;
            s.pop();
            tmp /= 3;
        }
    }
    if(!s.empty()) return 0;
    return ans;
}

int main(){
    cin >> str;
    cout << foo();
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;

stack <char> s;
string str;

ll ans(){
    int len = str.length();

    ll answer = 0, tmp = 1;
    for(int i = 0; i < len; i++){
        if(str[i] == '(') tmp *= 2, s.push(str[i]);
        else if(str[i] == '[') tmp *= 3, s.push(str[i]);
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '(') return 0;
            if(str[i - 1] == '(') answer += tmp;
            s.pop(), tmp /= 2;
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() != '[') return 0;
            if(str[i - 1] == '[') answer += tmp;
            s.pop(), tmp /= 3;
        }
    }

    if(!s.empty()) return 0;
    return answer;
}

int main(){
    cin >> str;
    cout << ans();
}
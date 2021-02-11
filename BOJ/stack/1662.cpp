#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

string str;
bool chk[50];

int foo(int tmp, int start){
    stack <char>s;
    int a = 0, ans = 0;
    for(int i = start; i < str.length(); i++){
        if(chk[i]) continue;
        chk[i] = true;
        if(str[i] == ')') break;
        if(str[i] == '(' && !s.empty()) {a = s.top() - '0', ans += foo(a, i+1), s.pop(); continue;}
        s.push(str[i]);
    }
    while(!s.empty()) ans++, s.pop();
    return tmp*ans;
}

int main(){
    stack <char>s;
    int ans = 0, tmp = 0;
    cin >> str;
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < str.length(); i++){
        if(chk[i]) continue;
        chk[i] = true;
        if(str[i] == '(' && !s.empty()) {tmp = s.top() - '0', ans += foo(tmp, i+1), s.pop(); continue;}
        s.push(str[i]);
    }
    while(!s.empty()) ans++, s.pop();
    cout << ans;
}
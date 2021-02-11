#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
#define ll long long
string str;
map <char, int>m;
bool chk[100];

int foo(int start){
    ll ans = 0, tmp = 1, a = 1;
    stack <char>s;
    for(int i = start; i < str.length(); i++){
        if(chk[i]) continue;
        chk[i] = true;
        if(str[i] == ')') {if(i+1 < str.length() && str[i+1] >= '2' && str[i+1] <= '9') chk[i+1] = true, tmp = str[i+1] - '0'; break;}
        if(str[i] == '(') {ans += foo(i+1); continue;}
        s.push(str[i]);
    }    
    while(!s.empty()){
        if(s.top() >= '2' && s.top() <= '9') a = s.top() - '0';
        else ans += m[s.top()] * a, a = 1;
        s.pop();
    }
    return tmp * ans;
}

int main(){
    ll ans = 0, a =1;
    stack <char>s;
    memset(chk, false, sizeof(chk));
    m['C'] = 12, m['H'] = 1, m['O'] = 16;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(chk[i]) continue;
        chk[i] = true;
        if(str[i] == '(') {ans += foo(i+1); continue;}
        s.push(str[i]);
    }
    while(!s.empty()){
        if(s.top() >= '2' && s.top() <= '9') a = s.top() - '0';
        else ans += m[s.top()] * a, a = 1;
        s.pop();
    }
    cout << ans;
}
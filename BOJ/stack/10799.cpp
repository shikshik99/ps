#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <char>v;
string tmp;

int foo(){
    int cnt = 0;
    for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] == '(') v.push(tmp[i]);
        if(tmp[i] == ')' && tmp[i-1] == '(') {v.pop(); cnt += v.size();}
        if(tmp[i] == ')' && tmp[i-1] == ')') {v.pop(); cnt++;}
    }
    return cnt;
}

int main(){
    cin >> tmp;
    cout << foo();
}
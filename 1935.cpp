#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

stack <double>s;
vector <double>v;
string str;

void foo(int num){
    double a, b;
    if(num == 0){
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(a+b);
    }
    else if(num == 1){
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(a-b);
    }
    else if(num == 2){
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(a*b);
    }
    else if(num == 3){
        b = s.top(); s.pop();
        a = s.top(); s.pop();
        s.push(a/b);
    }
}

int main(){
    int N;
    cin >> N >> str;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+') foo(0);
        else if (str[i] == '-') foo(1);
        else if (str[i] == '*') foo(2);
        else if (str[i] == '/') foo(3);
        else s.push(v[str[i] - 65]);
    }
    printf("%.2f", s.top());
}
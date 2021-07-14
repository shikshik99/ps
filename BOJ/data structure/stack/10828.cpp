#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <int> s;

void TOP(){
    if(s.empty()) cout << -1 << '\n';
    else cout << s.top() << '\n';
}

void EMPTY(){
    if(s.empty()) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void SIZE(){
    cout << s.size() << '\n';
}

void POP(){
    if(s.empty()) {
        cout << -1 << '\n'; return;
    }
    cout << s.top() << '\n', s.pop();
}

void PUSH(int num){
    s.push(num);
}

int main(){
    string str, num;
    int N;
    cin >> N;

    while(N--){
        cin >> str;
        if(str == "push"){
            cin >> num;
            PUSH(stoi(num));
        }
        else if(str == "pop") POP(); 
        else if(str == "size") SIZE();
        else if(str == "empty") EMPTY();
        else if(str == "top") TOP();
    }
}
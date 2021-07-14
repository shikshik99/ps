#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque <int> dq;

void PUSH(int num){
    dq.push_back(num);
}

void POP(){
    if(dq.empty()) cout << -1 << '\n';
    else cout << dq.front() << '\n', dq.pop_front();
}

void SIZE(){
    cout << dq.size() << '\n';
}

void EMPTY(){
    if(dq.empty()) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void FRONT(){
    if(dq.empty()) cout << -1 << '\n';
    else cout << dq.front() << '\n';
}

void BACK(){
    if(dq.empty()) cout << -1 << '\n';
    else cout << dq.back() << '\n';
}

int main(){
    string str, num;
    int N;
    cin >> N;
    while(N--){
        cin >> str;
        if(str == "push") cin >> num, PUSH(stoi(num));
        else if(str == "pop") POP();
        else if(str == "size") SIZE();
        else if(str == "empty") EMPTY();
        else if(str == "front") FRONT();
        else if(str == "back") BACK();
    }
}
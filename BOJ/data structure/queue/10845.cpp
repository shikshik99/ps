#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque <int> dq;
int N;

void cmd(int f, int num){
    switch(f){
        case 0 :
            dq.push_back(num);
            break;
        case 1 :
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n', dq.pop_front();
            break;
        case 2 :
            cout << dq.size() << '\n';
            break;
        case 3 :
            cout << dq.empty() << '\n';
            break;
        case 4 :
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
            break;
        case 5 :
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
            break;
    }
}

int main(){
    cin >> N;
    string str;
    int f, num;
    while(N--){
        cin >> str;
        if(str == "push") f = 0, cin >> num;
        else if(str == "pop") f = 1;
        else if(str == "size") f = 2;
        else if(str == "empty") f = 3;
        else if(str == "front") f = 4;
        else if(str == "back") f = 5;
        cmd(f, num);
    }
}
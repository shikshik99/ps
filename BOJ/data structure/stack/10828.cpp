#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
int N;

void cmd(int flag, int num){
    switch (flag)
    {
    case 0:
        s.push(num);
        break;
    case 1:
        if(s.empty()) cout << -1 << '\n';
        else cout << s.top() << '\n', s.pop();
        break;
    case 2:
        cout << s.size() << '\n';
        break;
    case 3:
        cout << s.empty() << '\n';
        break;
    case 4:
        if(s.empty()) cout << -1 << '\n';
        else cout << s.top() << '\n';
        break;
    default:
        break;
    }
}

int main(){
    cin >> N;
    string str;
    int flag, num;   
    while(N--){
        cin >> str;
        if(str == "push") {
            cin >> num;
            flag = 0;
        }
        else if(str == "pop") flag = 1;
        else if(str == "size") flag = 2;
        else if(str == "empty") flag = 3;
        else if(str == "top") flag = 4;
        cmd(flag, num);
    }
}
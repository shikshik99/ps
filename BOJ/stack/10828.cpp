#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <int> s;

int main(){
    int N;
    cin >> N;
    cin.ignore();
    string str, cmd, tmp;
    int A;
    while(N--){
        getline(cin, str);
        cmd.clear();
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' ') {tmp = str.substr(i + 1, str.length() - (i + 1)), A = stoi(tmp); break;}
            cmd += str[i];
        }
        if(cmd == "push") s.push(A);
        else if (cmd == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
        else if(cmd == "pop"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n', s.pop();
        }
        else if(cmd == "size") cout << s.size() << '\n';
        else if(cmd == "empty"){
            if(s.empty()) cout << 1 <<'\n';
            else cout << 0 << '\n'; 
        }
    }
}

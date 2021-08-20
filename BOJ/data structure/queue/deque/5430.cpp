#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque <int> dq;

void foo(string str){
    int len = str.length();
    if(len == 2) return;
    string tmp = "";
    for(int i = 1; i < len; i++){
        if(str[i] == ',' || str[i] == ']') dq.push_back(stoi(tmp)), tmp.clear();
        else tmp += str[i];
    }
}

void run(string str){
    bool f = true;
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(str[i] == 'R') f ^= true;
        else{
            if(dq.empty()){
                cout << "error\n";
                return;
            }
            if(f) dq.pop_front();
            else dq.pop_back();
        }
    }
    cout << '[';
    while(!dq.empty()){
        if(f) cout << dq.front(), dq.pop_front();
        else cout << dq.back(), dq.pop_back();
        
        if(!dq.empty()) cout << ',';
    }
    cout << "]\n";
}

int main(){
    string cmd, arr;
    int T, N;
    cin >> T;
    while(T--){
        cin >> cmd >> N >> arr;
        while(!dq.empty()) dq.pop_back();
        foo(arr);
        run(cmd);
    }
}
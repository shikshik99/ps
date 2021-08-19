#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <char> s;
int N;

int possible(string str){
    int len = str.length();
    if(len % 2) return 0;

    for(int i = 0; i < len; i++){
        if(s.empty() || str[i] != s.top()) {
            s.push(str[i]);
            continue;
        }
        
        s.pop();
    }

    if(!s.empty()) return 0;

    return 1;
}

int main(){
    cin >> N;

    string str;
    int answer = 0;
    for(int i = 0; i < N; i++){
        cin >> str;
        while(!s.empty()) s.pop();

        answer += possible(str);
    }

    cout << answer << '\n';
}
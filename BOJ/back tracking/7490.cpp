#include <bits/stdc++.h>
using namespace std;

vector <string> answer;
int T, N;

void foo(string str, int idx){
    string tmp = "";
    if(idx > N) {
        int num = 0;
        int len = str.length();
        for(int i = 0; i < len; i++){
            if(str[i] == '+' || str[i] == '-'){
                if(!tmp.empty()){
                    num += stoi(tmp);
                    tmp.clear();
                }
            }
            if(str[i] == ' ') continue;
            tmp += str[i];
        }
        num += stoi(tmp);
        if(!num) answer.push_back(str); 
        return;
    }
    
    if(idx == N) foo(str + to_string(idx), idx + 1);
    else{
        tmp = str + to_string(idx) + '+';
        foo(tmp, idx + 1);
        tmp = str + to_string(idx) + '-';
        foo(tmp, idx + 1);
        tmp = str + to_string(idx) + ' ';
        foo(tmp, idx + 1);
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        foo("", 1);
        sort(answer.begin(), answer.end());
        for(string str : answer) cout << str << '\n';
        answer.clear();
        cout << '\n';
    }
}
#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

vector<deque<int>> v;
vector<string> answer;
string cmd, str, foo;

void my_split(int idx, string tmp){
    int num = 0;
    if(tmp.length() == 2) return;
    for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] >= '0' && tmp[i] <= '9') {
            num *= 10;
            num += (tmp[i] - '0');
        }
        else if((tmp[i] == ',' || tmp[i] == ']')) v[idx].push_back(num), num = 0;
    }
}

int main(){
    int T, tmp;
    cin >> T;
    v.resize(T);
    for(int i = 0; i < T; i++){
        cmd.clear(), str.clear();
        cin >> cmd >> tmp >> str;
        my_split(i, str);
        bool flag = true;
        for(int j = 0; j < cmd.length(); j++){
            if(cmd[j] == 'R') flag = flag ^ true;
            else{
                if(v[i].empty()) {answer.push_back("error"); break;}
                else{
                    if(flag) v[i].pop_front();
                    else v[i].pop_back();
                }
            }
        }
        if(v[i].empty()) {
            if(i == answer.size()) {answer.push_back("[]"); continue;}
            else continue;
        }
        foo.clear();
        foo += '[';
        if(flag){
            while(!v[i].empty()){
                foo += to_string(v[i].front()), v[i].pop_front();
                if(v[i].empty()) foo += ']';
                else foo +=',';
            }
        }
        else {
            while(!v[i].empty()){
                foo += to_string(v[i].back()), v[i].pop_back();
                if(v[i].empty()) foo += ']';
                else foo += ',';
            }
        }
        answer.push_back(foo);
    }
    for(auto it : answer) cout << it << '\n';
}
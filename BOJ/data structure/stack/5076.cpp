#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector <string> foo(string str){
    vector <string> v;
    
    int len = str.length();
    int idx, cnt = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '<') {
            cnt = 1;
            idx = i;
            while(i < len && str[i] != '>') cnt++, i++;
            i--;
            v.push_back(str.substr(idx, cnt));
        }
    }

    return v;
}

bool possible(string str){
    stack <string> s;
    vector <string> v = foo(str);

    string tmp;
    int cnt;
    for(auto it : v) {
        tmp.clear();
        cnt = 0;
        if(it[it.length() - 2] == '/') continue;
        if(it[1] == '/') {
            tmp = it.substr(2, it.length() - 3);
            if(s.empty() || s.top() != tmp) return false;
            s.pop();
        }
        else{
            for(int i = 1; i < it.length(); i++){
                if(it[i] == '>' || it[i] == ' ') break;
                cnt++;
            }
            tmp = it.substr(1, cnt);
            s.push(tmp);
        }
    }

    if(s.size()) return false;
    return true;
}

int main(){
    string str = "";
    bool f;
    getline(cin, str);

    while(str != "#"){
        if(possible(str)) cout << "legal\n";
        else cout << "illegal\n";
        getline(cin, str);
    }
}
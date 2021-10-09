#include <bits/stdc++.h>
using namespace std;

map <string, bool> m;
int T;

vector<string> split(string str, char ch){
    vector <string> ret;

    int len = str.length();
    string tmp;
    for(int i = 0; i < len; i++){
        if(str[i] == ch) ret.push_back(tmp), tmp.clear();
        else tmp += str[i];
    }
    ret.push_back(tmp);

    return ret;
}

int main(){
    cin >> T;
    cin.ignore();
    
    string str;
    while(T--){
        m.clear();
        getline(cin, str);
        vector <string> ret = split(str, ' ');
        for(auto it : ret) m[it] = true;
        while(getline(cin, str)){
            if(str == "what does the fox say?") break;
            vector <string> tmp = split(str, ' ');
            m[tmp[2]] = false;
        }
        for(auto it : ret){
            if(m[it]) cout << it << ' ';
        }
        cout << '\n';
    }
}
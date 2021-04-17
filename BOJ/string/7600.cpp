#include <iostream>
#include <string>
#include <map>
using namespace std;

map <char, int> m;

string foo(string tmp){
    string str;
    for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] >= 'A' && tmp[i] <= 'Z') str += tmp[i] - 'A' + 'a';
        else if(tmp[i] >= 'a' && tmp[i] <= 'z') str += tmp[i];
    }
    return str;
}

int main(){
    string str;
    int cnt;
    getline(cin, str);
    while(str != "#"){
        str = foo(str);
        m.clear(), cnt = 0;
        for(auto it : str) m[it]++;
        for(auto it : m){
            if(it.second > 0) cnt++;
        }
        cout << cnt << '\n';
        getline(cin, str);
    }
}
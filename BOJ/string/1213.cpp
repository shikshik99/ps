#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map <char, int>m;
string s;

int main(){
    cin >> s;
    bool flag = false;
    char a;
    for(auto it : s) m[it]++;
    for(auto it : m){
        if(it.second % 2) {
            if(flag) {cout << "I'm Sorry Hansoo"; return 0;}
            flag = true, a = it.first;
        }
    }
    s.clear();
    if(flag){
        for(auto it : m){
                for(int i = 0; i < it.second/2; i++) s += it.first;
        }
        cout << s << a, reverse(s.begin(), s.end()); cout << s;   
    }
    else {
        for(auto it : m){
            for(int i = 0; i < it.second/2; i++) s += it.first;
        }
        cout << s, reverse(s.begin(), s.end()); cout << s;
    }
}
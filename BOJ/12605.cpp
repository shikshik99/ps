#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
string tmp;
stack <string>s[5];

int main(){
    int N;
    cin >> N;
    getline(cin, str);
    for(int i = 0; i < N; i++){
        str = "";
        tmp = "";
        getline(cin, str);
        for(int j = 0; j < str.length(); j++){
            if(str[j] == ' ' || str[j] == '\n') {s[i].push(tmp); tmp = "";}
            else tmp += str[j];
        }
        s[i].push(tmp);
    }
    for(int i = 0; i < N; i++){
        cout << "Case #" << i+1 << ':';
        while(!s[i].empty()){ cout << ' ' << s[i].top(); s[i].pop();}
        cout << '\n';
    }
}


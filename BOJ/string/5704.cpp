#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector <char>answer;

int main(){
    string str = "";
    bool a = false;
    getline(cin, str);
    while(str != "*"){
        for(int i = 0; i < 26; i++){
            if(str.find('a' + i) == string::npos) {answer.push_back('N'); a = false; break;}
            else a = true;
        }
        if(a) answer.push_back('Y');
        getline(cin, str);
    }
    for(auto it : answer) cout << it << '\n';
}
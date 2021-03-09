#include <iostream>
#include <string>
using namespace std;

int main(){
    long long answer = 0;
    string s, tmp;
    getline(cin, s);
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == ',') answer += stoi(tmp), tmp = "";
        else tmp += s[i];
    }
    cout << answer + stoi(tmp);
}
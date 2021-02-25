#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int>answer;

int main(){
    string str;
    for(int i = 0; i < 5; i++){
        cin >> str;
        for(int j = 0; j < str.length() - 2 ; j++){
            if(str.substr(j, 3) == "FBI") {answer.push_back(i+1); break;}
        }
    }
    if(answer.empty()) {cout << "HE GOT AWAY!"; return 0;}
    for(auto it : answer) cout << it << ' ';    
}
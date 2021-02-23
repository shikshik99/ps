#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> answer;

void AND(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '1' && b[i] == '1') answer[0] += '1';
        else answer[0] += '0';
    }
}

void OR(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '1' || b[i] == '1') answer[1] += '1';
        else answer[1] += '0';
    }
}

void XOR(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '1' && b[i] == '0') answer[2] += '1';
        else if(a[i] == '0' && b[i] == '1') answer[2] += '1';
        else answer[2] += '0';
    }
}

void NOT(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '1') answer[3] += '0';
        else if(a[i] == '0') answer[3] += '1';
        if(b[i] == '1') answer[4] += '0';
        else if(b[i] == '0') answer[4] +='1';
    }
}

int main(){
    string a, b;
    cin >> a >> b;
    answer.resize(5);
    AND(a,b), OR(a,b), XOR(a,b), NOT(a,b);
    for(auto it : answer) cout << it << '\n';
}
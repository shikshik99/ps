#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <char>s;
string str;

int main(){
     int N, K;
     cin >> N >> K >> str;

     for(int i = 0; i < str.length(); i++){
         while(K && !s.empty() && s.top() - '0' < str[i] - '0') s.pop(), K--;
         s.push(str[i]);             
     }
     str.clear();
    while(!s.empty()) str += s.top(), s.pop();
    for(int i = str.length() - 1; i >= K; i--) cout << str[i];
}
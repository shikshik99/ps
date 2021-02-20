#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 0, b = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.length()/2; i++)a += (str[i]-'0');
    for(int i = str.length()/2 ; i < str.length(); i++) b += (str[i]- '0');
    if(a==b)cout << "LUCKY";
    else cout << "READY";
}
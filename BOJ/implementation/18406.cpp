#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int cnt0 = 0, cnt1 = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(i < str.length() / 2) cnt1 += (str[i] - '0');
        else cnt0 += (str[i] - '0');
    }
    if(cnt0 == cnt1) cout << "LUCKY\n";
    else cout << "READY\n";
}
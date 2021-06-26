#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    int cnt0 = 0, cnt1 = 0;
    bool flag0 = false, flag1 = false;
    cin >> str;
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == '0') {
            cnt0++;
            while(str[i] == '0') i++;
        }
    }
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == '1') {
            cnt1++;
            while(str[i] == '1') i++;
        }
    }
    cout << min(cnt0, cnt1);
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, str2;

int main(){
    int N, K, cnt, i = 0;
    char tmp;
    cin >> N >> K;
    str.resize(N, '?');
    while(K--){
        cin >> cnt >> tmp;
        while(cnt--){
            i--; if(i < 0) i += N;
        }
        if(str[i] != '?' && str[i] != tmp){cout << '!'; return 0;}
        str[i] = tmp;
    }
    str2 = str;
    sort(str2.begin(), str2.end());
    tmp = str2[0];
    for(int a = 1; a < str2.length(); a++) {
        if(tmp == str2[a] && tmp != '?') { cout << '!'; return 0;}
        tmp = str2[a];
    }
    for(cnt = 0; cnt < N; cnt++) cout << str[i], i++, i %= N;
}
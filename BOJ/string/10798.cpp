#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str[5];
string ans;

int main() {
    for(int i = 0; i < 5; i++) cin >> str[i];
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
        if(i >= str[j].size()) continue;
        ans += str[j][i];
        }
    }
    cout << ans;
}
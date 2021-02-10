#include <iostream>
#include <string>
using namespace std;
#define ll long long
string str1, str2;

int main(){
    cin >> str1 >> str2;
    ll ans = 0;
    for(int i = 0; i < str1.length(); i++){
        for(int j = 0; j < str2.length(); j++){
            ans += (str1[i] - '0') * (str2[j] - '0');
        }
    }
    cout << ans;
}
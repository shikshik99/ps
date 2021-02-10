#include <iostream>
#include <string>
using namespace std;

string str;

int main(){
    int ans = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z') ans += str[i] - 'a' + 1;
        else if(str[i] >= 'A' && str[i] <= 'Z') ans += str[i] - 'A' + 27;
    }
    if(ans == 1){cout << "It is not a prime word."; return 0;}
    for(int i = 2; i < ans; i++) if(!(ans % i)){cout << "It is not a prime word."; return 0;}
    cout << "It is a prime word.";
}
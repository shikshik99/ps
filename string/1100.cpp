#include <iostream>
#include <string>
using namespace std;

string str, tmp;

int main(){
    int ans = 0;
    for(int i = 0; i < 8; i++) cin >> tmp, str +=tmp;
    for(int i = 0; i < str.length(); i++){
        if((i / 8) % 2 == 0 && i % 2 == 0 && str[i] == 'F') ans++;
        else if((i / 8) % 2 == 1 && i % 2 == 1 && str[i] == 'F') ans++; 
    }
    cout << ans;
}
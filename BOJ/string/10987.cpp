#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int answer = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++) if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') answer++;
    cout << answer;
}
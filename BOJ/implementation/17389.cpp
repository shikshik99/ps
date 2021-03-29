#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, answer = 0, cnt = 0;
    string str;
    cin >> N >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'X') cnt = 0;
        else answer += i + cnt + 1, cnt++;
    }
    cout << answer;
}
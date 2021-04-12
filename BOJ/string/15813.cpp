#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, answer = 0;
    string str;
    cin >> N >> str;
    for(int i = 0; i < N; i++) answer += str[i] - 'A' + 1;
    cout << answer;
}
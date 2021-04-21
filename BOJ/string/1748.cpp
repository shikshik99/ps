#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, cnt = 0, i = 1;
    cin >> N;
    while(i <= N){
        if(i * 10 <= N) cnt = cnt + ((i * 10) - i) * to_string(i).length(), i *= 10;
        else {cnt = cnt + (N - i + 1) * to_string(i).length(); break;}
    }
    cout << cnt;
}
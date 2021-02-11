#include <iostream>
#include <string>
using namespace std;

int main(){
    string N;
    int M, i = 0, cnt = 0;
    cin >> N >> M;
    for(i = 0; i < N.length(); i++) cnt = cnt * 10 + (N[i] - '0');
    cnt *= N.length();
    i = 0;
    while(i < cnt && i < M) cout << N[i%N.length()], i++;
}
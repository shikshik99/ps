#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
    int N, K, cnt = 0, ans = 0;
    cin >> N >> K;
    bitset <32>bit = N;
    string str = bit.to_string();
    for(int i = 0; i < str.length(); i++) if(str[i] == '1') cnt++;
    N += 1; bit = N;
    while(cnt > K){
        cnt = 0;
        str = bit.to_string();
        for(int i = 0; i < str.length(); i++) if(str[i] == '1') cnt++;
        N += 1; bit = N;
        ans++;
    }
    cout << ans << '\n';
}
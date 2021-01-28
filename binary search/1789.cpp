#include <iostream>
using namespace std;
#define ll long long


int main(){
    ll S, cnt = 0, tmp = 0, i = 1;
    cin >> S;
    while(tmp <= S){
        tmp += i;
        i++; cnt++;
    }
    cout << cnt-1;
}
#include <iostream>
using namespace std;

int main(){
    int K, cntA = 0, cntB = 1, tmp;
    cin >> K;
    K--;
    while(K--) tmp = cntB, cntB = cntA + cntB, cntA = tmp;
    cout << cntA << ' ' << cntB;
}
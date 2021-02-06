#include <iostream>
using namespace std;

int main(){
    int N, A, B, C, D;
    int cnt1 = 0, cnt2 = 0, price1 = 0, price2 = 0;
    cin >> N >> A >> B >> C >> D;
    while(cnt1 < N) cnt1 += A, price1 += B;
    while(cnt2 < N) cnt2 += C, price2 += D;
    cout << (price1 < price2 ? price1 : price2);
}
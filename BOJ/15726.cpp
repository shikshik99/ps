#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    double A, B, C;
    int tmp1, tmp2;
    cin >> A >> B >> C;
    tmp1 = A * B / C;
    tmp2 = A / B * C;
    cout << max(tmp1, tmp2);
}
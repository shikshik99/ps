#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int tmp = b;
    b *= d, a *= d, c *= tmp;
    a += c;
    tmp = gcd(a, b);
    cout << a / tmp << ' ' << b / tmp << '\n';
}
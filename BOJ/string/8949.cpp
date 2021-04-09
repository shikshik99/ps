#include <iostream>
#include <string>
using namespace std;

int main(){
    int A, B, tmp;
    string str;
    cin >> A >> B;
    tmp = A > B ? A : B;
    B = A < B ? A : B;
    A = tmp;
    while(A){
        str = to_string(A % 10 + B % 10) + str;
        A /= 10, B /= 10;
    }
    cout << str;
}
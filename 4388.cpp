#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A, B;
vector <int> v;

void foo(){
    int cnt, carry, ma, mi, tmp;
    while(1){
        cnt = 0, carry = 0;
        cin >> A >> B;
        if(A == "0" && B == "0") return;
        ma = A.length() > B.length() ? A.length() : B.length();
        mi = A.length() < B.length() ? A.length() : B.length();
        if(ma == B.length()) swap(A,B);
        while(mi >= 0){
            tmp = (A[ma--] - '0') + (B[mi--] - '0') + carry;
            if(tmp >= 10) carry = 1, cnt++;
            else carry = 0;
        }
        while(ma >= 0){
            tmp = (A[ma--] - '0') + carry;
            if(tmp >= 10) carry = 1, cnt++;
            else carry = 0;
        }
        v.push_back(cnt);
    }
}

int main(){
    foo();
    for(auto it : v) cout << it << '\n';
}
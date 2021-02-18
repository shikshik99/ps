#include <iostream>
using namespace std;

int main(){
    int num, a, tmp;
    cin >> num;
    for(int i = 1; i <= num; i++){
        a = i, tmp = i;
        while(a>0){
            tmp += a % 10, a/=10;
        }
        if(tmp == num) {cout << i; return 0;}
    }
    cout << 0;
}

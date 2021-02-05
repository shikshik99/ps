#include <iostream>
using namespace std;

int main(){
    int N, F;
    cin >> N >> F;
    N -= (N%100);
    for(int i = 0; i < 100; i++){
        N += i;
        if(N%F == 0){
            if(!i) {cout << "00"; return 0;}
            else if(i < 10) {cout << '0' << i; return 0;}
            else {cout << i; return 0;}
        }
        N -= i;
    }
}
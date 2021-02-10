#include <iostream>
using namespace std;

int main(){
    int i = 0, N, cnt = 0;
    cin >> N;
    while(cnt != N){
        i++;
        int tmp = i;
        while(tmp > 100){
            if(tmp % 1000 == 666) {cnt++; break;}
            tmp /= 10;
        }
    }
    cout << i;
}
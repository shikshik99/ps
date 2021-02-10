#include <iostream>
using namespace std;

int A, T, B, ans;

int foo(){
    int cnt = 0, cnt0 = 0, cnt1 = 0;
    while(1){
        for(int i = 0; i < 4; i++){
            if(i%2 == 0) cnt0++;
            else cnt1++;
            if(cnt0 == T && !B) return cnt0 + cnt1 - 1;
            if(cnt1 == T && B) return cnt0 + cnt1 - 1;
        }
        for(int i = 0; i < cnt+2; i++){
            cnt0++;
            if(cnt0 == T && !B) return cnt0 + cnt1 - 1;
        }
        for(int i = 0 ; i < cnt+2; i++){
            cnt1++;
            if(cnt1 == T && B) return cnt0 + cnt1 - 1;
        }
        cnt++;
    }
}

int main(){
    cin >> A >> T >> B;
    ans = foo();
    cout << ans%A;
}
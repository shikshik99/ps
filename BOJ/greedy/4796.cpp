#include <iostream>
using namespace std;

int main(){
    int L, P, V = 1; // P일중 L일 동안만 사용 가능 휴가 기간은 V
    int idx = 1, ans;
    cin >> L >> P >> V;
    while(L || P || V){
        ans = (V / P) * L, V %= P;
        ans += (V >= L ? L : V);
        cout << "Case " << idx++ << ": " << ans << '\n';
        cin >> L >> P >> V;
    }
}
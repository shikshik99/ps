#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int mush[10], sum = 0, ans = 0;
    for(int i = 0; i < 10;i++) {
        cin >> mush[i];
    }
    for(int i = 0; i < 10; i++){
        sum += mush[i];
        int a = abs(100 - sum);
        int b = abs(100 - ans);
        if(a < b) ans = sum;
        else if (a == b) ans = max(ans,sum);
    }
    cout << ans;

    return 0;
}
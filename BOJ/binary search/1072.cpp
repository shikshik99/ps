#include <iostream>
#define MAX 1000000000
using namespace std;
using ll = long long;

int main(){
    ll X, Y, Z;
    cin >> X >> Y;
    Z = 100 * Y / X;
    if(Z >= 99) cout << -1 << '\n', exit(0);

    int l = 0, r = MAX, mid;
    ll tmp;
    while(l <= r){
        mid = (l + r) / 2;
        tmp = 100 * (Y + mid) / (X + mid);
        if(tmp > Z) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << '\n';
}
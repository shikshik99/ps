#include <iostream>
using namespace std;
#define ll long long

int main(){
    ll X, Y, Z;
    cin >> X >> Y;
    Z = 100 * Y / X;

    ll answer = -1;
    ll l = 0, r = 1000000000, mid, tmp;
    while(l <= r){
        mid = (l + r) / 2;
        tmp = 100 * (Y + mid) / (X + mid);
        if(tmp > Z) answer = mid, r = mid - 1;
        else l = mid + 1;
    }
    
    cout << answer << '\n';
}
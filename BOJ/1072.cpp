#include <iostream>
using namespace std;
#define num 1000000000
#define ll long long

int main(){
    ll x, y, z, left, right, mid, tmp;
    cin >> x >> y;
    z = 100 * y / x;
    if(z >= 99) {cout << -1; return 0;}
    left = 0;
    right = num;
    while(left <= right){
        mid = (right+left)/2;
        tmp = 100 * (y + mid)/(x + mid);
        if(tmp > z) right = mid - 1;
        else left = mid + 1;
    }
    cout << left;
}
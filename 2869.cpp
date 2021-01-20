#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double A, B, V;
    int ans;
    cin >> A >> B >> V;
    ans = ceil((V - A) / (A - B));
    cout << ans + 1;
}
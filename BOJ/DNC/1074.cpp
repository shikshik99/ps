#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

int foo(int x, int y, int depth){
    if(!depth) return 0;

    int mid = pow(2, depth) / 2;
    int tmp = pow(2, depth - 1);
    
    if(r < x + mid && c < y + mid) return foo(x, y, depth - 1);
    else if(r < x + mid && c >= y + mid) return (tmp * tmp) + foo(x, y + mid, depth - 1);
    else if(r >= x + mid && c < y + mid) return (tmp * tmp) * 2 + foo(x + mid, y, depth - 1);
    else return (tmp * tmp) * 3 + foo(x + mid, y + mid, depth - 1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> r >> c;
    cout << foo(0, 0, N);
}
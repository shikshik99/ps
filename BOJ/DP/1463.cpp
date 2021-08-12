#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000001
using namespace std;

int D[MAX];

int foo(int X){
    if(X == 1) return 0;

    int &ret = D[X];
    if(ret != -1) return ret;

    ret = 1;

    if(!(X % 3) && !(X % 2)) ret += min({foo(X / 3), foo(X / 2), foo(X - 1)});
    else if(!(X % 3)) ret += min(foo(X / 3), foo(X - 1));
    else if(!(X % 2)) ret += min(foo(X / 2), foo(X - 1));
    else ret += foo(X - 1);

    return ret;
}

int main(){
    int X;
    cin >> X;
    memset(D, -1, sizeof(D));
    cout << foo(X);
}
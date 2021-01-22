#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N, a, b, cnt = 1, ma, mi;
    cin >> N >> a >> b;
    ma = max(a,b);
    mi = min(a,b);
    while(1){
        if(ma % 2 != 1 && ma - 1 == mi) break;
        if(ma%2 == 1) ma = (ma/2) + 1;
        else ma = ma/2;
        if(mi%2 == 1) mi= (mi/2) + 1;
        else mi = mi/2;
        cnt++;
    }
    cout << cnt;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int answer = 0x7f7f7f7f, tmp;
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int cnt = max(X, Y);
    while(cnt >= 0){
        tmp = 0;
        tmp += C * (cnt * 2);
        if(X - cnt > 0) tmp += (X - cnt) * A;
        if(Y - cnt > 0) tmp += (Y - cnt) * B;
        answer = min(answer, tmp), cnt--;
    }
    cout << answer << '\n';
}
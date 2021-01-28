#include <iostream>
#include <stack>
using namespace std;

stack <int>s;

int main(){
    unsigned int a, K, ans = 0;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a;
        ans += a;
        if(!a) {
            ans -= s.top();
            s.pop();
        }
        else s.push(a);
    }
    cout << ans;
}
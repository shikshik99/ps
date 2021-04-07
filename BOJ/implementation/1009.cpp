#include <iostream>
#include <vector>
using namespace std;

vector <int>answer;

int main(){
    long long T,a, b, tmp;
    cin >> T;
    while(T--){
        tmp = 1;
        cin >> a >> b;
        while(b--) tmp *= a, tmp %= 10;
        answer.push_back(tmp);
    }
    for(auto it : answer) {
        if(!it) cout << 10 << '\n';
        else cout << it << '\n';
    }
}
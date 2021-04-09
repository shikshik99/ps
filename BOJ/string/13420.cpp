#include <iostream>
using namespace std;

int main(){
    long long A, B, ans, N;
    char a, b;
    cin >> N;
    while(N--){
        cin >> A >> a >> B >> b >> ans;
        if(a == '+'){
            if(A + B == ans) cout << "correct";
            else cout << "wrong answer";
        }
        else if(a == '-'){
            if(A - B == ans) cout << "correct";
            else cout << "wrong answer";
        }
        else if(a == '*'){
            if(A * B == ans) cout << "correct";
            else cout << "wrong answer";
        }
        else if(a == '/'){
            if(A / B == ans) cout << "correct";
            else cout << "wrong answer";
        }
        cout << '\n';
    }
}
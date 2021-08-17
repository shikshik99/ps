#include <iostream>
#include <stack>
#include <string>
using namespace std;

double arr[26];
stack <double> s;

int main(){
    int N;
    string str;
    cin >> N >> str;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < str.length(); i++){
        char tmp = str[i];
        if(tmp >= 'A' && tmp <= 'Z') s.push(arr[tmp - 'A']);
        else {
            double B = s.top(); s.pop();
            double A = s.top(); s.pop();
            switch(tmp){
                case '+' :
                    s.push(A + B);
                    break;
                case '-' :
                    s.push(A - B);
                    break;
                case '*' :
                    s.push(A * B);
                    break;
                case '/' :
                    s.push(A / B);
                    break;
            }
        }
    }
    printf("%.2f", s.top());
}
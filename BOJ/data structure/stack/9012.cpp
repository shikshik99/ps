#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    string str;
    cin >> N;
    p :
    while(N--){
        cin >> str;
        int cnt = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') cnt++;
            else cnt--;
            if(cnt < 0) {
                cout << "NO\n";
                goto p;
            }
        }
        if(cnt) cout << "NO\n";
        else cout << "YES\n";
    }
}
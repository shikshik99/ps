#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int ans = 0x7f7f7f7f, tmp;
    string a, b;
    cin >> a >> b;
    if(a.length() == b.length()){
        tmp = 0;
        for(int i = 0; i < a.length();i++){
            if(a[i] != b[i]) tmp++;
        }
        cout << tmp; return 0;
    }
    else{
        for(int i = 0; i < b.length() - a.length() + 1; i++){
            tmp = 0;
            for(int j = i; j < a.length() + i; j++){
                if(b[j] != a[j-i]) tmp++;
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans;
}
#include <iostream>
#include <string>
using namespace std;

string ans, tmp;

int main(){
    cin >> tmp;
    ans = tmp + "0000";
    int flag = 0;
    int j = ans.length()-1;
    for(int i = tmp.length()-1; i >= 0; i--){
        int sum = (tmp[i]-'0') + (ans[j]-'0') + flag;
        if(!sum) ans[j] = '0';
        else if (sum == 1) ans[j] = '1', flag = 0;
        else if (sum == 2) ans[j] = '0', flag = 1;
        else if (sum == 3) ans[j] = '1', flag = 1;
        j--;
    }
    while(j >= 0){
        int sum  = (ans[j]-'0') + flag;
        if(!sum) ans[j] = '0';
        else if (sum == 1) ans[j] = '1', flag = 0;
        else if (sum == 2) ans[j] = '0', flag = 1;
        else if (sum == 3) ans[j] = '1', flag = 1;
        j--;
    }
    if(flag) ans = "1" + ans;
    cout << ans;
}
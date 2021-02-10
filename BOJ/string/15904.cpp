#include <iostream>
#include <string>
using namespace std;

string str, ans = "UCPC";

int main(){
    int i = 0 ,j = 0;
    getline(cin, str);
    while(i < str.length() && j < ans.length()){
        if(str[i] == ans[j]) j++;
        i++;
    }
    if(j > 3) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";
}
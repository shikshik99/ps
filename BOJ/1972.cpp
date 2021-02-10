#include <iostream>
#include <string>
#include <set>
using namespace std;

string str[101];
string tmp;
set <string>s;
bool chk[101] = {false};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    cin >> str[0];
    while(str[cnt-1] != "*") {cin >> str[cnt]; cnt++;}
    cnt -= 1;

    for(int i = 0; i < cnt; i++){
        if(str[i].length() == 1 || str[i].length() == 2) continue;
        int n = str[i].length();
        for(int j = 1; j <= n - 1; j++){
            if(chk[i]) break;
            for(int k = 0; k < n-j; k++){
                tmp = "";
                if(chk[i]) break;
                tmp += str[i].at(k);
                tmp += str[i].at(k+j);
                if(s.count(tmp)) chk[i] = true;
                else s.insert(tmp);
            }
            s.clear();
        }
    }
    for(int i = 0; i < cnt; i++){
        if(chk[i]) cout << str[i] << " is NOT surprising.\n";
        else cout << str[i] << " is surprising.\n";
    }
}
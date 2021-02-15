#include <iostream>
#include <string>
using namespace std;

string a, b;

int foo(){
    int ans = 0, tmp = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ',') ans +=tmp, tmp = 0;
        else{
            tmp = tmp * 10 + (a[i]-'0');
        }
    }

    return ans + tmp;
}

int main(){
    a = "";
    while(!cin.eof()){
        getline(cin, b);
        a += b;
    }
    cout << foo();
}
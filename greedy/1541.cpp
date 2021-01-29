#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector <int>v;

int foo(){
    int cnt = 0, plus = 0 , minus = 0;
    bool flag = false;
    plus += v[0];
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-' && !flag) {cnt++; minus += v[cnt]; flag = true;}
        else if(str[i] == '+' && flag) {cnt++; minus+=v[cnt];}
        else if(str[i] == '+' && !flag) {cnt++; plus +=v[cnt];}
        else if(str[i] == '-' && flag) {cnt++; minus += v[cnt];}
    }
    return plus - minus;
}

int main(){
    cin >> str;
    int ans = 0, tmp = 0, pivot = 0, a = 0, f = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-' || str[i] == '+'){
            tmp = 0, a =  i - 1, f = 1;
            while(a>=pivot){
                tmp += (str[a]-'0') * f;
                f *= 10;
                a--;
            }
            v.push_back(tmp);
            pivot = i + 1;
        }
    }
    tmp = 0, a =  str.length()-1, f = 1;
    while(a>=pivot){
        tmp += (str[a]-'0') * f;
        f *= 10;
        a--;
    }
    v.push_back(tmp);
    cout << foo();
}
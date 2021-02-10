#include <iostream>
#include <string>
using namespace std;

string str, N;

int main(){
    int i;
    cin >> N;
    str.resize(N.size()); 
    for(i = 0; i < str.size(); i++) str[i] = '0';
    i = 0;
    while(i < str.size()){
        str[i] = '7';
        if(stoi(str) > stoi(N)) str[i] = '4';
        if(stoi(str) > stoi(N) && i == 0) str[i] = '0';
        else if(stoi(str) > stoi(N)) {i--; continue;}
        i++;
    }
    cout << stoi(str);
}
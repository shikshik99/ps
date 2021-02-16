#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string str = "";
    vector <string>v;
    getline(cin,str);
    while(str != "END") reverse(str.begin(), str.end()), v.push_back(str), getline(cin, str);
    for(auto it : v) cout << it << '\n';
}
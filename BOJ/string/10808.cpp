#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> v(26, 0);

int main(){
    string str;
    cin >> str;
    for(auto it : str) v[it-'a']++;
    for(auto it : v) cout << it << ' ';
}
#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;

map <string, ll> m;
int cnt = 0;

int main(){
    string str;
    getline(cin, str);
    while(!cin.eof()) {
        m[str]++, cnt++;
        getline(cin, str);
    }

    cout << fixed;
    cout.precision(4);
    for(auto it : m) cout << it.first << ' ' << (100 * it.second) / (double)cnt << '\n';
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a, b, ans;
    cin >> a >> b;
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
    ans = to_string(stoi(a) + stoi(b));
    reverse(ans.begin(), ans.end());
    cout << stoi(ans);
}
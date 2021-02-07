#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map <char,int>m1, m2;
string a,b;

int main(){
    int answer = 0;
    cin >> a >> b;
    for(int i = 0; i < 26; i++) m1['a' + i] = m2['a' + i] = 0;
    for(int i = 0; i < a.length(); i++) m1[a[i]]++;
    for(int i = 0; i < b.length(); i++) m2[b[i]]++;
    for(int i = 0; i < 26; i++) answer += max(m1['a' + i], m2['a' + i]) - min(m1['a' + i], m2['a' + i]);
    cout << answer;
}
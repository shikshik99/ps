#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
map <string, ll> A,B;
vector <string>v;

void foo(){
    A["black"] = 0; B["black"] = 1;
    A["brown"] = 1; B["brown"] = 10; 
    A["red"] = 2; B["red"] = 100;
    A["orange"] = 3; B["orange"] = 1000; 
    A["yellow"] = 4; B["yellow"] = 10000;
    A["green"] = 5; B["green"] = 100000;
    A["blue"] = 6; B["blue"] = 1000000;
    A["violet"] = 7; B["violet"] = 10000000;
    A["grey"] = 8; B["grey"] = 100000000;
    A["white"] = 9; B["white"] = 100000000;
}

int main(){
    string str;
    for(int i = 0; i < 3; i++) cin >> str, v.push_back(str);
    foo();
    ll ans = 0;
    ans += A[v[0]] * 10;
    ans += A[v[1]];
    ans *= B[v[2]];
    cout << ans;
}
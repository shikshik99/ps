#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector <string> ans;
map <char, int>m1, m2;
int N;

void foo(){
    string a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        m1.clear(), m2.clear();
        for(int j = 0; j < a.length(); j++) m1[a[j]]++;
        for(int j = 0; j < b.length(); j++) m2[b[j]]++;
        if(m1 == m2) a += " & " + b + " are anagrams.";
        else a += " & " + b + " are NOT anagrams.";
        ans.push_back(a);
    }
}

int main(){
    cin >> N;
    foo();
    for(auto it : ans) cout << it << '\n';   
}
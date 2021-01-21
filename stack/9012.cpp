#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

stack <char>s;
vector <string>v;
int N;

void foo(){
    for(int i = 0; i < N; i++){
        while(!s.empty()) s.pop();
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] == '(') s.push(v[i][j]);
            else if (v[i][j] == ')' && !s.empty() && s.top() == '(') s.pop();
            else if (v[i][j] == ')' && s.empty()) s.push(v[i][j]);
        }
        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }    
}

int main(){
    cin >> N;
    cin.ignore();
    v.resize(N);
    for(int i = 0; i < N; i++) getline(cin, v[i]);
    foo();
}
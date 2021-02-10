#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector <string>v;
stack <char>s;
char tmp;
int N;

void foo(){
    int cnt = 0;
    char pivot;
    for(int i = 0; i < N; i++){
        while(!s.empty()) s.pop();
        for(int j = 0; j < v[i].length(); j++) {
            if(!s.empty() && s.top() == v[i][j]) s.pop();
            else s.push(v[i][j]);
        }
        if(s.empty()) cnt++;
    }
    cout << cnt;
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {cin >> v[i];}
    foo();
}
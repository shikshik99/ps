#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <vector<string>>v;
vector <string> tmp;
stack <string> s;
int N;

bool cmp(string a, string b){
    if(a.length() == b.length()) return a < b ? true : false;
    if(a.length() != b.length()){
        if(a[0] != b[0]) return a[0] < b[0]? true : false;
        else return a.length() < b.length()? true : false;
    }
}

void foo(){
    auto it = tmp.begin();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            while(!s.empty() && s.top() == *it && it != tmp.end()) s.pop(), it++;
            if(v[i][j] != *it) s.push(v[i][j]);
            else if(v[i][j] == *it) it++;
        }
    }
    while(!s.empty() && s.top() == *it && it != tmp.end()) s.pop(), it++;
    if(s.empty()) cout << "GOOD";
    else cout << "BAD";
}

int main(){
    string str;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            cin >> str, v[i].push_back(str), tmp.push_back(str);
        }
    }
    sort(tmp.begin(), tmp.end(), cmp);
    foo();
}
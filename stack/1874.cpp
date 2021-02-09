#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack <int>s;
vector <int>v;
vector <char>ans;

int main(){
    int N, cnt = 1, i = 0;
    cin >> N;
    v.resize(N);
    for(i = 0; i < N; i++)cin >> v[i];
    i = 0;
    while(i < N){
        if(!s.empty() && cnt > N && s.top() != v[i]){cout << "NO"; return 0;}
        if(!s.empty() && s.top() == v[i]) {s.pop(), ans.push_back('-'), i++; continue;}
        while(cnt != v[i] + 1 && cnt <= N) s.push(cnt++), ans.push_back('+');
    }
    for(auto it : ans) cout << it << '\n';
}
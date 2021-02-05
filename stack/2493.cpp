#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
vector <int> v, ans;
stack <int> s;

void foo(){
    s.push(0);
    for(int i = 1; i < N; i++){
        if(s.empty()) {s.push(i); continue;}
        else if(!s.empty() && v[s.top()] > v[i]){
            ans[i] = s.top() + 1;
            s.push(i);
            continue;
        }
        else if(!s.empty() && v[s.top()] < v[i]){
            while(!s.empty() && v[s.top()] < v[i]){
                s.pop();
                if(!s.empty() && v[s.top()] > v[i]) { ans[i] = s.top() + 1; }
            }
        s.push(i);
        }
    }
}

int main(){
    cin >> N;
    v.resize(N);
    ans.resize(N);
    for(int i = 0; i < N; i++) {cin >> v[i]; ans[i] = 0;}
    foo();
    for(auto it : ans) cout << it << ' ';
}
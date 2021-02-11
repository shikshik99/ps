#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define ll long long
stack <int>s;
vector <int>v;

int main(){
    ll N, ans = 0;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        if(s.empty()) {s.push(v[i]); continue;}
        else if(s.top() > v[i]) {s.push(v[i]); continue;}
        while(!s.empty() && s.top() <= v[i]){
            s.pop(), ans += s.size();
        }
        s.push(v[i]);
    }
    while(!s.empty()) s.pop(), ans += s.size();
    cout << ans;
}
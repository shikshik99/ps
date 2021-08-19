#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

vector <stack<int>> v;
int N, P;

int main(){
    v.resize(6);

    cin >> N >> P;
    
    int idx, num;
    ll answer = 0;
    for(int i = 0 ; i < N; i++){
        cin >> idx >> num;
        idx--;
        while(!v[idx].empty() && v[idx].top() > num) v[idx].pop(), answer++;
        if(v[idx].empty() || v[idx].top() != num) v[idx].push(num), answer++;
    }

    cout << answer << '\n';
}
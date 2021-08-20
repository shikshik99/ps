#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

vector <queue <int>> v;

int main(){
    v.resize(21);

    int N, K;
    cin >> N >> K;

    ll answer = 0;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        int len = str.length();
        while(!v[len].empty() && (i - v[len].front()) > K) v[len].pop();
        answer += v[len].size();
        v[len].push(i);
    }

    cout << answer << '\n';
}
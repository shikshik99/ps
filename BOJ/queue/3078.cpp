#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <queue<int>> v;

int main(){
    long long N, K, ans = 0;
    cin >> N >> K;
    string str;
    v.resize(21);
    for(int i = 0; i < N; i++) {
        cin >> str;
        int sizz = str.length();
        while(!v[sizz].empty() && i - v[sizz].front() > K) v[sizz].pop();
        ans += v[sizz].size();
        v[sizz].push(i);
    }

    cout << ans;
}
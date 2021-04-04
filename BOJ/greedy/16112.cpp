#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
long long cnt, answer;

int main(){
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0;
    while(k--) answer += v[i] * cnt, cnt++, i++;
    while(i < n) answer += v[i] * cnt, i++;
    cout << answer;
}
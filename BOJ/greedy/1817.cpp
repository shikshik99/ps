#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;
    int answer = 1, num = 0, tmp = 0;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(num + tmp > M) tmp = num, answer++;
        else tmp += num;
    }
    if(!N) cout << 0 << '\n';
    else cout << answer << '\n';
}
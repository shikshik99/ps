#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;

int main(){
    int N, K, answer = 0;
    cin >> N >> K;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < N; i++){
        if(K/v[i]) answer += K/v[i], K %= v[i];
    }
    cout << answer;
}
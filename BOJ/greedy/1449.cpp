#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;

int main(){
    int N, L, answer = 1;
    cin >> N >> L;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int tmp = L - 1;
    for(int i = 1; i < N; i++){
        if(!tmp) {tmp = L - 1, answer++; continue;}
        if(v[i] - v[i-1] <= tmp) tmp -= (v[i] - v[i-1]);
        else tmp = L - 1, answer++;
    }
    cout << answer;
}
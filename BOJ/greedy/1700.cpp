#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>

vector <int> v;
vector <int> elec;

int main(){
    int N, K, answer = 0, idx = 0;
    bool flag = false;
    pii tmp;
    cin >> N >> K;
    v.resize(N, 0), elec.resize(K);
    for(int i = 0; i < K; i++) cin >> elec[i];

    for(int i = 0; i < K; i++){
        tmp.first = tmp.second = 0;
        flag = false;
        for(int j = 0; j < N; j++){
            if(v[j] == elec[i]) {flag = true; break;}
            if(!v[j]) {v[j] = elec[i]; flag = true; break;}
        }
        if(flag) continue;
        for(int j = 0; j < N; j++){
            idx = i + 1;
            while(idx < K && elec[idx] != v[j]) idx++;
            if(idx == K) {v[j] = elec[i]; answer++; flag = true; break;}
            if(tmp.second < idx) tmp.first = elec[idx], tmp.second = idx;
        }
        if(flag) continue;
        for(int j = 0; j < N; j++){
            if(tmp.first == v[j]) {v[j] = elec[i]; answer++; flag = true; break;}
        }
    }

    cout << answer << '\n';
}
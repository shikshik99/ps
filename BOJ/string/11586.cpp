#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string>v;

int main(){
    int N, K;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cin >> K;
    if(K == 1){
        for(auto it : v) cout << it << '\n';
    }
    else if(K == 2){
        for(int i = 0; i < N; i++) {
            for(int j = v[i].size() - 1; j >= 0; j--) cout << v[i][j];
            cout << '\n';
        }
    }
    else if(K == 3){
        for(int i = N-1; i >= 0; i--) cout << v[i] << '\n';
    }
}
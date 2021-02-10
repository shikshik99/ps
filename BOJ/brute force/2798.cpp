#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;

int main(){
    int N, M, ans = 0, tmp = 0;
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                tmp = v[i] + v[j] + v[k];
                if(tmp <= M) ans = max(ans, tmp);
            }
        }
    }
    cout << ans;
}
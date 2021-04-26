#include <iostream>
#include <vector>
using namespace std;

vector <int> v, tmp;

int main(){
    int N, pivot, cnt;
    cin >> N;
    v.resize(N, 0x6f6f6f6f);
    tmp.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> tmp[i];
    for(int i = 0; i < N; i++){
        pivot = tmp[i];
        cnt = 0;
        for(int j = 0; j < N; j++){
            if(cnt == pivot && v[j] == 0x6f6f6f6f){v[j] = i; break;}
            if(i < v[j]) {cnt++; continue;}
        }
    }
    for(auto it : v) cout << it + 1 << ' ';
}
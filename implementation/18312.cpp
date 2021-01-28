#include <iostream>
using namespace std;

int main(){
    int N, K, cnt = 0;
    cin >> N >> K;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < 60; j++){
            for(int l = 0; l < 60; l++){
                if(i/10 == K) {cnt++; continue;}
                if(i%10 == K) {cnt++; continue;}
                if(j/10 == K) {cnt++; continue;}
                if(j%10 == K) {cnt++; continue;}
                if(l/10 == K) {cnt++; continue;}
                if(l%10 == K) {cnt++; continue;}
            }
        }
    }
    cout << cnt;
    return 0;
}
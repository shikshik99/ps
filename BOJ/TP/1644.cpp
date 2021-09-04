#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 4000001
using namespace std;

vector <int> v;
bool chk[MAX];
int N;

int main(){
    memset(chk, true, sizeof(chk));
    cin >> N;
    chk[1] = true;
    for(int i = 2; i <= N; i++){
        if(chk[i]) v.push_back(i);
        else continue;
        for(int j = i * 2; j <= N; j += i){
            chk[j] = false;
        }
    }

    int len = v.size(), s = 0, e = 0;
    int psum = 0, answer = 0;
    while(s < len){
        if(e == len || psum >= N){
            psum -= v[s++];
        }
        else psum += v[e++];
        if(psum == N) answer++;
    }

    cout << answer << '\n';
}
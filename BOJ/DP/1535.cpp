#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int D[MAX][101];
int L[MAX], J[MAX];
int N;
int answer = 0;

int foo(int idx, int health){
    if(idx == N) return 0;
    int &ret = D[idx][health];
    if(ret != -1) return ret;

    ret = foo(idx + 1, health);
    if(health - L[idx] > 0) ret = max(ret, foo(idx + 1, health - L[idx]) + J[idx]);

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) cin >> J[i];
    
    memset(D, -1, sizeof(D));
    cout << foo(0, 100) << '\n';
}
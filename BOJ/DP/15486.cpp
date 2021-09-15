#include <bits/stdc++.h>
#define MAX 1500001
using namespace std;

int day[MAX], money[MAX];
int D[MAX];
int N;

int foo(int idx){
    if(idx >= N) return 0;
    
    int &ret = D[idx];
    if(ret != -1) return ret;

    ret = foo(idx + 1);
    if(idx + day[idx] <= N) ret = max(ret, foo(idx + day[idx]) + money[idx]);

    return ret;
}


int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> day[i] >> money[i];
    }
    
    cout << foo(0) << '\n';
}
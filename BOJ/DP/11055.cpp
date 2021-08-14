#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[1001], arr[1001];
int N;

int foo(int idx){
    if(idx == N) return 0;
    
    int &ret = D[idx];
    if(ret != -1) return ret;
    ret = arr[idx];

    for(int i = idx + 1; i < N; i++){
        if(arr[idx] < arr[i]) ret = max(ret, foo(i) + arr[idx]);
    }

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int answer = 0;
    for(int i = 0; i < N; i++) answer = max(answer, foo(i));

    cout << answer << '\n';
}
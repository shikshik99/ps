#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 16
using namespace std;

int arr[MAX];
int N;

bool possible(int depth){
    for(int i = 0; i < depth; i++){
        if(arr[i] == arr[depth]) return false;
        if(abs(i - depth) == abs(arr[i] - arr[depth])) return false;
    }

    return true;
}

int foo(int depth){
    if(depth == N) return 1;
    int ret = 0;
    
    for(int i = 0; i < N; i++){
        arr[depth] = i;
        if(possible(depth)) ret += foo(depth + 1);
    }

    return ret;
}

int main(){
    cin >> N;
    memset(arr, -1, sizeof(arr));

    cout << foo(0) << '\n';
}
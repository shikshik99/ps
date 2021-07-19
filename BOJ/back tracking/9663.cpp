#include <iostream>
#include <cmath>
using namespace std;

int arr[16];
int N;

bool chk(int depth){
    for(int i = 0; i < depth; i++){
        if(arr[i] == arr[depth]) return false;
        if(abs(i - depth) == abs(arr[i] - arr[depth])) return false;
    }

    return true;
}

int foo(int depth){
    if(depth == N) return 1;
    int answer = 0;
    
    for(int i = 0; i < N; i++){
        arr[depth] = i;
        if(chk(depth)) answer += foo(depth + 1);
    }

    return answer;
}

int main(){
    for(int i = 0; i < 16; i++) arr[i] = -1;
    cin >> N;
    cout << foo(0);
}
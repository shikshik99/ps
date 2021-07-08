#include <iostream>
#include <cmath>
using namespace std;

int arr[16];
int N;

bool ok(int depth){
    for(int i = 0; i < depth; i++){
        if(arr[depth] == arr[i]) return false;
        if(abs(depth - i) == abs(arr[depth] - arr[i])) return false;
    }
    
    return true;
}

int foo(int depth){
    if(depth == N) return 1;
    int answer = 0;
    for(int i = 0; i < N; i++){
        arr[depth] = i;
        if(ok(depth)) answer += foo(depth + 1);
    }
    
    return answer;
}

int main(){
    cin >> N;
    cout << foo(0);
}
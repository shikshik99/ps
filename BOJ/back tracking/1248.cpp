#include <bits/stdc++.h>
using namespace std;

char arr[10][10];
int ans[10];
int N;

bool possible(int idx){
    for(int i = 0; i < idx + 1; i++){
        int psum = 0;
        char ch;
        for(int j = i; j < idx + 1; j++){
            psum += ans[j];
            if(psum < 0) ch = '-';
            else if(psum == 0) ch = '0';
            else ch = '+';
            
            if(ch != arr[i][j]) return false;
        }
    }

    return true;
}

void foo(int idx){
    if(idx == N){
        for(int i = 0; i < N; i++) cout << ans[i] << ' ';
        cout << '\n';
        exit(0);
    }

    for(int i = -10; i <= 10; i++){
        ans[idx] = i;
        if(possible(idx)) foo(idx + 1);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++) cin >> arr[i][j];
    }

    foo(0);
}

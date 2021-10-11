#include <bits/stdc++.h>
#define MAX 51
using namespace std;

char A[MAX][MAX], B[MAX][MAX];
int N, M;

void flip(int x, int y){
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(A[i][j] == '1') A[i][j] = '0';
            else A[i][j] = '1';
        }
    }
}

bool possible(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M ; j++) {
            if(A[i][j] != B[i][j]) return false;
        }
    }

    return true;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M ; j++) cin >> A[i][j];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M ; j++) cin >> B[i][j];
    }

    int answer = 0;
    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++){
            if(A[i][j] != B[i][j]) flip(i, j), answer++;
        }
    }

    if(possible()) cout << answer << '\n';
    else cout << -1 << '\n';
}
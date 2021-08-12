#include <iostream>
#define MAX 6562
using namespace std;

char board[MAX][MAX];
int N;

void foo(int x, int y, int depth){
    if(depth == 3){
        for(int i = x; i < x + 3; i++){
            for(int j = y; j < y + 3; j++){
                if(i == x + 1 && j == y + 1) continue;
                board[i][j] = '*';
            }
        }
        return;
    }

    int tmp = depth / 3;
    for(int i = x; i < x + depth; i += tmp){
        for(int j = y; j < y + depth; j += tmp){
            if(i == x + tmp && j == y + tmp) continue;
            foo(i, j, tmp);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = ' ';
        }
    }
    foo(0, 0, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}  
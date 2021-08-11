#include <iostream>
#define MAX 64
using namespace std;

int board[MAX][MAX];
int N;

bool chk_board(int x, int y, int len){
    int pivot = board[x][y];
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(board[i][j] != pivot) return false;
        }
    }

    return true;
}

void foo(int x, int y, int len){
    if(chk_board(x, y, len)){
        cout << board[x][y];
        return ;
    }

    int tmp = len / 2;
    cout << '(';
    for(int i = x; i < x + len; i += tmp){
        for(int j = y; j < y + len; j += tmp){
            foo(i, j, tmp);
        }
    }
    cout << ')';
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) scanf("%1d", &board[i][j]);
    }

    foo(0, 0, N);
}
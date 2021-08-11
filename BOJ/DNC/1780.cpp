#include <iostream>
#define MAX 2188
using namespace std;

int board[MAX][MAX];
int answer[3] = {0, };
int N;

bool chk_board(int x, int y, int len){
    int pivot = board[x][y];

    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(pivot != board[i][j]) return false;
        }
    }

    return true;
}

void foo(int x, int y, int len){
    if(len == 1 || chk_board(x, y, len)) {
        int ret = ++board[x][y];
        answer[ret]++;
        return;
    }

    int tmp = len / 3;
    for(int i = x; i < x + len; i += tmp){
        for(int j = y; j < y + len; j += tmp){
            foo(i, j, tmp);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    foo(0, 0, N);
    cout << answer[0] << '\n' <<  answer[1] << '\n' << answer[2] << '\n';
}
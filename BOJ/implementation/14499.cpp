#include <iostream>
#include <vector>
using namespace std;

vector <int> dice;
int N, M, x, y, K;
int dicex, dicey;
vector <vector<int>> board;

void foo(int idx){
    switch (idx)
    {
    case 1:
        if(dicey + 1 < M) {
            dicey++, dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
            if(!board[dicex][dicey]) board[dicex][dicey] = dice[6];
            else dice[6] = board[dicex][dicey], board[dicex][dicey] = 0;
            cout << dice[1] << '\n';
        }
        break;
    case 2:
        if(dicey - 1 >= 0){
            dicey--, dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
            if(!board[dicex][dicey]) board[dicex][dicey] = dice[6];
            else dice[6] = board[dicex][dicey], board[dicex][dicey] = 0;
            cout << dice[1] << '\n';
        }
        break;
    case 3:
        if(dicex - 1 >= 0){
            dicex--, dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
            if(!board[dicex][dicey]) board[dicex][dicey] = dice[6];
            else dice[6] = board[dicex][dicey], board[dicex][dicey] = 0;
            cout << dice[1] << '\n';
        }
        break;
    case 4:
        if(dicex + 1 < N){
            dicex++, dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
            if(!board[dicex][dicey]) board[dicex][dicey] = dice[6];
            else dice[6] = board[dicex][dicey], board[dicex][dicey] = 0;
            cout << dice[1] << '\n';
        }
        break;
    }
}

int main() {
    cin >> N >> M >> x >> y >> K;
    dice.resize(7, 0);
    dicex = x, dicey = y;
    board.resize(N);
    for(int i = 0; i < N; i++) board[i].resize(M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> x, board[i][j] = x;
    }
    while(K--){
        cin >> x;
        foo(x);
    }
}
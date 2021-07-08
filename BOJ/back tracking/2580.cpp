#include <iostream>
#include <vector>
using namespace std;
#define pii pair <int, int>

int board[9][9];
vector <pii> v;

void print_board(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}

bool ok(int x, int y){
    for(int i = 0; i < 9; i++){
        if(i != x && board[i][y] == board[x][y]) return false;
        if(i != y && board[x][i] == board[x][y]) return false;
    }
    int dx = (x / 3) * 3, dy = (y / 3) * 3;
    for(int i = dx; i < dx + 3; i++){
        for(int j = dy; j < dy + 3; j++){
            if(i == x && j == y) continue;
            if(board[i][j] == board[x][y]) return false;       
        }
    }

    return true;
}

void foo(int idx){
    if(idx == v.size()) print_board(), exit(0);
    int x = v[idx].first, y = v[idx].second;
    for(int i = 1; i < 10; i++){
        board[x][y] = i;
        if(ok(x, y)) foo(idx + 1);
        board[x][y] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(!board[i][j]) v.push_back({i, j});
        }
    }

    foo(0);
}
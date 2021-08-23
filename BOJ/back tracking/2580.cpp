#include <iostream>
#include <vector>
using namespace std;
using pii = pair <int, int>;

int board[9][9];
vector <pii> v;
int N;

void print_board(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool possible(int x, int y, int num){
    for(int i = 0; i < 9; i++){
        if(i != x && board[i][y] == num) return false;
        if(i != y && board[x][i] == num) return false;
    }
    int dx = (x / 3) * 3;
    int dy = (y / 3) * 3;
    for(int i = dx; i < dx + 3; i++){
        for(int j = dy; j < dy + 3; j++){
            if(i == x && j == y) continue;
            if(board[i][j] == board[x][y]) return false;
        }
    }

    return true;
}

void foo(int depth){
    if(depth == N) print_board(), exit(0);

    int x = v[depth].first;
    int y = v[depth].second;
    for(int i = 1; i <= 9; i++){
        board[x][y] = i;
        if(possible(x, y, i)) foo(depth + 1);
        board[x][y] = 0;
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(!board[i][j]) v.push_back({i, j});
        }
    }
    
    N = v.size();
    foo(0);
}
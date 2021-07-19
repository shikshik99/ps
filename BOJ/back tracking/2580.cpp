#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int board[9][9];
vector <pii> v;
int sizz;

bool OK(int idx){
    int x = v[idx].first;
    int y = v[idx].second;
    for(int i = 0; i < 9; i++){
        if(board[x][y] == board[x][i] && i != y) return false;
        if(board[x][y] == board[i][y] && i != x) return false;
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

void print_board(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void foo(int idx){
    if(idx == sizz) print_board(), exit(0);
    
    for(int i = 1; i < 10; i++){
        int x = v[idx].first;
        int y = v[idx].second;
        board[x][y] = i;
        if(OK(idx)) foo(idx + 1);
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

    sizz = v.size();
    foo(0);
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> chess;
vector <string> v;
int answer = 0x7f7f7f7f;

void BLACK(int x, int y){
    int tmp = 0;
    v.clear();
    v.resize(8);
    for(int i = x; i < x+8; i++){
        for(int j = y; j < y+8; j++){
            v[tmp].push_back(chess[i][j]);
        }
        tmp++;
    }
    tmp = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!(i % 2) && !(j % 2) && v[i][j] == 'W') tmp++;
            else if(!(i % 2) && (j % 2) == 1 && v[i][j] == 'B') tmp++;
            else if((i % 2) == 1 && !(j % 2) && v[i][j] == 'B') tmp++;
            else if((i % 2) == 1 && (j % 2) == 1 && v[i][j] == 'W') tmp++;
        }
    }
    tmp = tmp < 64 - tmp ? tmp : 64 - tmp;
    answer = answer < tmp ? answer : tmp;
}

void WHITE(int x, int y){
    int tmp = 0;
    v.clear();
    v.resize(8);
    for(int i = x; i < x+8; i++){
        for(int j = y; j < y+8; j++){
            v[tmp].push_back(chess[i][j]);
        }
        tmp++;
    }
    tmp = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!(i % 2) && !(j % 2) && v[i][j] == 'B') tmp++;
            else if(!(i % 2) && (j % 2) == 1 && v[i][j] == 'W') tmp++;
            else if((i % 2) == 1 && !(j % 2) && v[i][j] == 'W') tmp++;
            else if((i % 2) == 1 && (j % 2) == 1 && v[i][j] == 'B') tmp++;
        }
    }
    tmp = tmp < 64 - tmp ? tmp : 64 - tmp;
    answer = answer < tmp ? answer : tmp;
}

int main(){
    int N, M;
    cin >> N >> M;
    chess.resize(N);
    for(int i = 0; i < N; i++) cin >> chess[i];
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            if(chess[i][j] == 'B') BLACK(i, j);
            else WHITE(i,j);
        }
    }
    cout << answer;
}
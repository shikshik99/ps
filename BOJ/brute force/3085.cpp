#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];
int N;

int get_max(){
    int ret = 0, tmp = 1;
    for(int i = 0; i < N; i++){
        ret = max(ret, tmp), tmp = 1;
        for(int j = 0; j < N - 1; j++){
            if(board[i][j] == board[i][j + 1]) tmp++;
            else ret = max(ret, tmp), tmp = 1;
        }
        
    }

    for(int i = 0; i < N; i++){
        ret = max(ret, tmp), tmp = 1;
        for(int j = 0; j < N - 1; j++){
            if(board[j][i] == board[j + 1][i]) tmp++;
            else ret = max(ret, tmp), tmp = 1;
        }
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j != N - 1){
                swap(board[i][j], board[i][j + 1]);
                answer = max(answer, get_max());
                swap(board[i][j], board[i][j + 1]);
            }
            if(i != N - 1){
                swap(board[i][j], board[i + 1][j]);
                answer = max(answer, get_max());
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }
    
    cout << answer << '\n';
}
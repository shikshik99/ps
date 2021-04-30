#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <pii>v;
vector <int>dir;
int board[8][8];
int max_rotate[6] = {0, 4, 2, 4, 4, 1};
int N, M, answer = 0x6f6f6f6f;

void copy_map(int A[][8], int B[][8]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            A[i][j] = B[i][j];
        }
    }
}

int get_answer(int arr[][8]){
    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 0) tmp++;
        }
    }
    return tmp;
}

void fill_map(int dir, int x, int y, int arr[][8]){
    dir %= 4;
    switch(dir){
        case 0:
            for(int i = x - 1; i >= 0; i--){
                if(arr[i][y] == 6) break;
                if(arr[i][y] == 0) arr[i][y] = -1;
            }
            break;
        case 1:
            for(int i = y + 1; i < M; i++){
                if(arr[x][i] == 6) break;
                if(arr[x][i] == 0) arr[x][i] = -1;
            }
            break;
        case 2:
            for(int i = x + 1; i < N; i++){
                if(arr[i][y] == 6) break;
                if(arr[i][y] == 0) arr[i][y] = -1;
            }
            break;
        case 3:
            for(int i = y - 1; i >= 0; i--){
                if(arr[x][i] == 6) break;
                if(arr[x][i] == 0) arr[x][i] = -1; 
            }
            break;
    }
}

void foo(int cc_num, int arr[][8]){
    if(cc_num == v.size()){
        answer = min(answer, get_answer(arr));
        return;
    }
    for(int i = 0; i < max_rotate[board[v[cc_num].first][v[cc_num].second]]; i++){
        int tmp[8][8];
        copy_map(tmp, arr);
        if(board[v[cc_num].first][v[cc_num].second] == 1){
            fill_map(i, v[cc_num].first, v[cc_num].second, tmp);
        }
        if(board[v[cc_num].first][v[cc_num].second] == 2){
            fill_map(i, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+2, v[cc_num].first, v[cc_num].second, tmp);
        }
        if(board[v[cc_num].first][v[cc_num].second] == 3){
            fill_map(i, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+1, v[cc_num].first, v[cc_num].second, tmp);
        }
        if(board[v[cc_num].first][v[cc_num].second] == 4){
            fill_map(i, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+1, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+2, v[cc_num].first, v[cc_num].second, tmp);
        }
        if(board[v[cc_num].first][v[cc_num].second] == 5){
            fill_map(i, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+1, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+2, v[cc_num].first, v[cc_num].second, tmp);
            fill_map(i+3, v[cc_num].first, v[cc_num].second, tmp);
        }
        foo(cc_num + 1, tmp);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5) v.push_back({i,j});
        }
    }
    
    foo(0, board);
    cout << answer;
}

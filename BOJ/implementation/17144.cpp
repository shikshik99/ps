#include <iostream>
#include <cstring>
using namespace std;

int arr[51][51];
int calc[51][51];
int direction[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int R, C, T, up = -1, down = -1;

void spread(){
    memset(calc, 0, sizeof(calc));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(arr[i][j] && arr[i][j] != -1){
                int cnt = 0, tmp = arr[i][j]/5;
                for(int k = 0; k < 4; k++){
                    int dx = i + direction[k][0];
                    int dy = j + direction[k][1];
                    if(dx < 0 || dx >= R || dy < 0 || dy >= C || arr[dx][dy] == -1) continue;
                    cnt++, calc[dx][dy] += tmp;
                }
                arr[i][j] -= (tmp * cnt);
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            arr[i][j] += calc[i][j];
        }
    }
}

void air_clean(){
    int x = up - 1, y = 0;
    for(x; x > 0; x--) arr[x][y] = arr[x - 1][y], arr[x - 1][y] = 0;
    x = 0, y = 0;
    for(y; y < C - 1; y++) arr[x][y] = arr[x][y + 1], arr[x][y+1] = 0;
    x = 0, y = C - 1;
    for(x; x < up; x++) arr[x][y] = arr[x + 1][y], arr[x + 1][y] = 0;
    x = up, y = C - 1;
    for(y; y > 1; y--) arr[x][y] = arr[x][y - 1], arr[x][y - 1] = 0;
    arr[up][1] = 0;

    x = down + 1, y = 0;
    for(x; x < R - 1; x++) arr[x][y] = arr[x + 1][y], arr[x + 1][y] = 0;
    x = R - 1, y = 0;
    for(y; y < C - 1; y++) arr[x][y] = arr[x][y + 1], arr[x][y + 1] = 0;
    x = R - 1, y = C - 1;
    for(x; x > down; x--) arr[x][y] = arr[x - 1][y], arr[x - 1][y] = 0;
    x = down, y = C - 1;
    for(y; y > 1; y--) arr[x][y] = arr[x][y - 1], arr[x][y - 1] = 0;
    arr[down][1] = 0;
}

int main(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < R; i++){
        if(up == -1 && arr[i][0] == -1) up = i;
        else if(up != -1 && arr[i][0] == -1) down = i;
    }
    while(T--){
        spread();
        air_clean();
    }
    long long answer = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(arr[i][j] == -1) continue;
            answer += arr[i][j];
        }
    }
    cout << answer;
}
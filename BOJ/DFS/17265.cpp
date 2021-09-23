#include <bits/stdc++.h>
using namespace std;

int arr[2][2] = {{0, 1}, {1, 0}};
char board[5][5];
int N;
int ma = -100000, mi = 0x6f6f6f6f;

int calc(string str){
    int len = str.length();
    int ret = (str[0] - '0');
    char ch;
    for(int i = 1; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            if(ch == '+') ret += (str[i] - '0');
            else if(ch == '-') ret -= (str[i] - '0');
            else if(ch == '*') ret *= (str[i] - '0');
        }
        else ch = str[i];
    }

    return ret;
}

void DFS(int x, int y, string str){
    str += board[x][y];
    if(x == N - 1 && y == N - 1){
        int num = calc(str);
        ma = max(ma, num);
        mi = min(mi, num);
        return;
    }
    for(int i = 0; i < 2; i++)  {
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
        DFS(dx,dy, str);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    DFS(0,0, "");
    cout << ma << ' ' << mi << '\n';
}
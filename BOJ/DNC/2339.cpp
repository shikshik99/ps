#include <iostream>
#define MAX 1001
using namespace std;

int board[MAX][MAX];
int N;

bool chk_garo(int x, int sy, int ey){
    for(int i = sy; i <= ey; i++){
        if(board[x][i] == 2) return false;
    }
    return true;
}

bool chk_sero(int y, int sx, int ex){
    for(int i = sx; i <= ex; i++){
        if(board[i][y] == 2) return false;
    }
    return true;
}

int foo(int sx, int sy, int ex, int ey, bool f){
    int impurity = 0, jewel = 0, ret = 0;

    for(int i = sx; i <= ex; i++){
        for(int j = sy; j <= ey; j++){
            if(board[i][j] == 1){
                impurity++;
                /* 경우의 수 성질에 의해 양쪽 경우의 수가 A, B 일 때 A * B 가 답 */
                if(f && chk_garo(i, sy, ey)) {
                    ret += (foo(sx, sy, i - 1, ey, false) * foo(i + 1, sy, ex, ey, false));
                }
                if(!f && chk_sero(j, sx, ex)) {
                    ret += (foo(sx, sy, ex, j - 1, true) * foo(sx, j + 1, ex, ey, true));
                }
            }
            if(board[i][j] == 2) jewel++;
        }
    }

    if(!jewel) return 0;
    if(!impurity){
        if(jewel == 1) return 1;
        else return 0;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int impurity = 0, jewel = 0, answer;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) impurity++;
            if(board[i][j] == 2) jewel++;
        }
    }

    if(!impurity){
        if(jewel == 1) cout << 1 << '\n';
        else cout << -1 << '\n';
        return 0;
    }

    answer = foo(0, 0, N - 1, N - 1, true) + foo(0, 0, N - 1, N - 1, false);

    if(answer) cout << answer << '\n';
    else cout << -1 << '\n';
}
#include <iostream>
#include <string>
#define MAX 21
using namespace std;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string board[MAX];
bool alpha[26], chk[MAX][MAX];
int N, M, answer = 0;

void foo(int x, int y, int cnt){
    alpha[board[x][y] - 'A'] = true;
    chk[x][y] = true;
    
    answer = answer > cnt ? answer : cnt;
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M || chk[dx][dy]) continue;
        char ch = board[dx][dy];
        if(alpha[ch - 'A']) continue;
        foo(dx, dy, cnt + 1);
    }
    alpha[board[x][y] - 'A'] = false;
    chk[x][y] = false;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];

    foo(0, 0, 1);
    cout << answer << '\n';
};
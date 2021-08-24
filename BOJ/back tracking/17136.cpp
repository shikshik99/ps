#include <iostream>
#define MAX 10
using namespace std;

int paper[6] = {0, };
bool board[MAX][MAX];
int answer = 26;

void Fill(int x, int y, int len, bool f){
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            board[i][j] = f;
        }
    }
}

void DFS(int cnt){
    if(cnt >= answer) return;
    int x = MAX, y = MAX;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(board[i][j]) x = i, y = j, i = MAX, j = MAX;
        }
    }
    
    if(x == MAX) {
        answer = answer < cnt ? answer : cnt;
        return;
    }

    for(int i = 5; i > 0; i--){
        bool f = true;
        if(paper[i] >= 5 || x + i > MAX || y + i > MAX) continue;
        for(int j = x; j < x + i; j++){
            for(int k = y; k < y + i; k++){
                if(!board[j][k]) f = false;
            }
        }
        if(!f) continue;

        Fill(x, y, i, false);
        paper[i]++;
        DFS(cnt + 1);
        paper[i]--;
        Fill(x, y, i, true);
    }
}

int main(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) cin >> board[i][j];
    }
    
    DFS(0);
    if(answer == 26) cout << -1 << '\n';
    else cout << answer << '\n';
}
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char board[51][51];
bool chk[51][51];
int water[51][51];

int R, C, x, y;

void flood(int a, int b){
    queue <pair<pii, int>>q;
    q.push({{a,b}, 0});
    chk[a][b] = true;

    while(!q.empty()){
        pii tmp = q.front().first; 
        int cnt = q.front().second + 1; q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || (water[dx][dy] != -1 && water[dx][dy] <= cnt) || board[dx][dy] == 'X' || board[dx][dy] == 'D') continue;
            water[dx][dy] = cnt;
            q.push({{dx,dy}, cnt});
        }
    }
}

int BFS(){
    memset(chk, false, sizeof(chk));
    queue <pair<pii, int>>q;
    q.push({{x,y}, 0}); 
    chk[x][y] = true;   

    while(!q.empty()){
        pii tmp = q.front().first; 
        int cnt = q.front().second + 1; q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= R || dy < 0 || dy >= C || (water[dx][dy] != -1 && water[dx][dy] <= cnt) || chk[dx][dy] || board[dx][dy] == 'X') continue;
            if(board[dx][dy] == 'D') return cnt;
            chk[dx][dy] = true;
            q.push({{dx,dy}, cnt});
        }
    }

    return -1;
}

int main(){
    memset(water, -1, sizeof(water));

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') x = i, y = j;
            if(board[i][j] == '*') water[i][j] = 0;
        }
    }
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(!water[i][j]) flood(i, j);
        }
    }

    int answer = BFS();
    if(answer == -1) cout << "KAKTUS\n";
    else cout << answer << '\n';
}
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define pii pair<int,int>

int arr[4][2] = {{-1,0},{1,0}, {0,1}, {0,-1}};
char board[12][6];
bool chk[12][6];
bool flag = false;
int answer = 0;

void bomb(int x, int y){
    queue <pii> q;
    vector <pii> v;
    int cnt = 1;
    q.push({x,y});
    v.push_back({x,y});
    chk[x][y] = true;
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= 12 || dy < 0 || dy >=6 || chk[dx][dy] || board[dx][dy] != board[tmp.first][tmp.second]) continue;
            q.push({dx,dy}), chk[dx][dy] = true;
            v.push_back({dx,dy}), cnt++;
        }
    }
    if(cnt >= 4){
        flag = true;
        for(int i = 0; i < v.size(); i++){
            board[v[i].first][v[i].second] = '.';
        }
    }
}

void foo(int x, int y, int cnt){
    if(!cnt) return;
    for(int i = x; i >= 0; i--){
        if(board[i][y] != '.') board[i+cnt][y] = board[i][y], board[i][y] = '.';
    }
}


void drop(){
    int cnt = 0;
    queue <char> tmp;
    for(int j = 0; j < 6; j++){
        cnt = 0;
        for(int i = 11; i >= 0; i--){
            if(board[i][j] != '.') tmp.push(board[i][j]);
        }
        for(int i = 11; i >= 0; i--){
            if(tmp.empty()) board[i][j] = '.';
            else board[i][j] = tmp.front(), tmp.pop();
        }
    }
}


int main(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++) cin >> board[i][j];
    }
    
    while(1){
        flag = false;
        memset(chk, false, sizeof(chk));
        for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++) if(board[i][j] != '.' && !chk[i][j]) bomb(i, j);
        }
        drop();
        if(!flag) {cout << answer; return 0;}
        answer++;
    }
}
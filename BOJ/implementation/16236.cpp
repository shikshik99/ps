#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define piii pair<pair<int, int>, int>
#define pii pair<int, int>

bool chk[21][21];
int board[21][21];
int arr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, sizz = 2, x, y, eaten = 0;

bool chk_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] && board[i][j] < sizz) return true;
        }
    }
    return false;
}

bool cmp(piii a, piii b){
    pii tmpa = a.first, tmpb = b.first;
    if(a.second == b.second){
        if(tmpa.first == tmpb.first){
            return tmpa.second < tmpb.second ? true : false;
        }
        else return tmpa.first < tmpb.first? true : false;
    }
    else return a.second < b.second ? true : false;
}

void eat(){
    eaten++;
    board[x][y] = 9;
    if(eaten >= sizz){
        eaten -= sizz;
        sizz++;
    }
}

int BFS(){
    memset(chk, false, sizeof(chk));

    queue <piii> q;
    vector <piii> v;
    q.push({{x,y}, 0});
    chk[x][y] = true;
    while(!q.empty()){
        pii tmp = q.front().first;
        int dist = q.front().second; q.pop();
        for(int i = 0; i < 4; i++){
            int dx = tmp.first + arr[i][0];
            int dy = tmp.second + arr[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || board[dx][dy] > sizz) continue;
            chk[dx][dy] = true;
            q.push({{dx, dy}, dist + 1});
            if(board[dx][dy] && board[dx][dy] < sizz) v.push_back({{dx,dy}, dist + 1});
        }
    }

    if(!v.empty()){
        sort(v.begin(), v.end(), cmp);
        board[x][y] = 0;
        x = v[0].first.first, y = v[0].first.second;

        eat();
        return v[0].second;
    }
    else return 0;
}

int main(){
    int answer = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) x = i, y = j;
        }
    }
    
    int tmp;
    while(chk_board()){
        tmp = BFS();
        if(!tmp) break;
        answer += tmp;
    }

    cout << answer << '\n';
}
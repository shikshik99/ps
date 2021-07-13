#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int, int>

bool chk[51][51];
char board[51][51];
int height_board[51][51];
int dir[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

vector <pii> house;
vector <int> height;
int post_x, post_y, N;

bool chk_board(){
    int sizz = house.size();
    for(int i = 0; i < sizz; i++){
        pii tmp = house[i];
        if(!chk[tmp.first][tmp.second]) return false;
    }

    return true;
}

bool BFS(int start, int end){
    int max_height = height[end], min_height = height[start];
    if(height_board[post_x][post_y] > max_height || height_board[post_x][post_y] < min_height) return false;

    memset(chk, false, sizeof(chk));
    queue <pii> q;
    q.push({post_x, post_y});
    chk[post_x][post_y] = true;
    
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        for(int i = 0; i < 9; i++){
            int dx = tmp.first + dir[i][0];
            int dy = tmp.second + dir[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || height_board[dx][dy] < min_height || height_board[dx][dy] > max_height) continue;
            q.push({dx, dy});
            chk[dx][dy] = true;
        }
    }
    if(chk_board()) return true;
    return false;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 'P') post_x = i, post_y = j;
            if(board[i][j] == 'K') house.push_back({i, j});
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> height_board[i][j];
            height.push_back(height_board[i][j]);
        }
    }

    sort(height.begin(), height.end());
    height.erase(unique(height.begin(), height.end()), height.end());

    int answer = 0x7f7f7f7f;
    int start = 0, end = 0, sizz = height.size();
    while(end < sizz){
        while(BFS(start, end)){
            answer = min(answer, (height[end] - height[start]));
            start++;
        }
        end++;
    }

    cout << answer << '\n';
}
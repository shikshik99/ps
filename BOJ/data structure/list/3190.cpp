#include <iostream>
#include <deque>
#include <cstring>
#define MAX 101
using namespace std;
using pic = pair <int, char>;
using pii = pair <int, int>;

deque <pii> snake;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int arr[MAX][MAX] = {0, };
pic v[MAX];
int N, K, L;
int cnt = 0, idx = 0;

bool chk_position(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;

    for(int i = 0; i < snake.size(); i++){
        if(x == snake[i].first && y == snake[i].second) return false;
    }

    return true;
}

int main(){
    cin >> N >> K;
    int x, y, direction = 0;
    for(int i = 0; i < K; i++) cin >> x >> y, arr[x - 1][y - 1] = 1;
    cin >> L;
    for(int i = 0; i < L; i++) cin >> v[i].first >> v[i].second;
    
    x = 0, y = 0;
    snake.push_front({x, y});
    while(1){
        cnt++;
        x = snake.front().first + dir[direction][0];
        y = snake.front().second + dir[direction][1];
        if(!chk_position(x, y)) cout << cnt << '\n', exit(0);
        
        snake.push_front({x, y});
        if(!arr[x][y]) snake.pop_back();
        arr[x][y] = 0;
        
        if(v[idx].first == cnt) {
            if(v[idx].second == 'L') direction = (direction - 1 + 4) % 4;
            else direction++, direction %= 4;
            idx++;
        }
    }
}
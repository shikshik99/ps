#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define pii pair<int, int>

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int pre[9] = {5, 10, 10, 7, 7, 2, 2, 1, 1};
int map[500][500];
int N, direction = -1, mov = 1, cnt = 0, answer = 0;

vector<vector<pii>> v;

void blow(int x, int y, int direction)
{
    int dx, dy, tmp, san = map[x][y];
    for(int i = 0; i < 9; i++){
        dx = x + v[direction][i].first;
        dy = y + v[direction][i].second;
        tmp = (map[x][y] * pre[i]) / 100;
        if(dx < 0 || dx >= N || dy < 0 || dy >= N) answer += tmp;
        else map[dx][dy] += tmp;
        san -= tmp;
    }
    dx = x + dir[direction][0];
    dy = y + dir[direction][1];
    if(dx < 0 || dx >= N || dy < 0 || dy >= N) answer += san;
    else map[dx][dy] += san;
    map[x][y] = 0;
}

void init_v()
{
    v.resize(4);
    v[0].resize(9), v[1].resize(9), v[2].resize(9), v[3].resize(9);
    v[0][0] = {0, -2}, v[0][1] = {-1, -1}, v[0][2] = {1, -1}, v[0][3] = {-1, 0}, v[0][4] = {1, 0}, v[0][5] = {-2, 0}, v[0][6] = {2, 0}, v[0][7] = {-1, 1}, v[0][8] = {1, 1};
    v[1][0] = {2, 0}, v[1][1] = {1, -1}, v[1][2] = {1, 1}, v[1][3] = {0, -1}, v[1][4] = {0, 1}, v[1][5] = {0, -2}, v[1][6] = {0, 2}, v[1][7] = {-1, -1}, v[1][8] = {-1, 1};
    v[2][0] = {0, 2}, v[2][1] = {-1, 1}, v[2][2] = {1, 1}, v[2][3] = {-1, 0}, v[2][4] = {1, 0}, v[2][5] = {-2, 0}, v[2][6] = {2, 0}, v[2][7] = {-1, -1}, v[2][8] = {1, -1};
    v[3][0] = {-2, 0}, v[3][1] = {-1, -1}, v[3][2] = {-1, 1}, v[3][3] = {0, -1}, v[3][4] = {0, 1}, v[3][5] = {0, -2}, v[3][6] = {0, 2}, v[3][7] = {1, -1}, v[3][8] = {1, 1};
}

int main()
{
    int x, y;
    cin >> N;
    x = y = N / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> map[i][j];

    init_v();
    while (1)
    {
        direction++;
        direction %= 4;
        int tmp = mov;
        while(tmp--){
            x = x + dir[direction][0];
            y = y + dir[direction][1];
            if (map[x][y]) blow(x, y, direction);
            if(!x && !y) break;
        }
        if(!x && !y) break;
        cnt++;
        if (!(cnt % 2)) mov++;
    }

    cout << answer;
}
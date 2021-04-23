#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct robot{
    int x, y, direction;
};

int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector <vector<int>> board;
vector <robot> v;

int main(){
    int A, B, N, M, x, y;
    char d;
    string str = "";
    cin >> A >> B >> N >> M;
    board.resize(B);
    for(int i = 0; i < B; i++) board[i].resize(A, -1);
    int tmp = B - 1, cnt = 0;
    while(N--){
        cin >> y >> x >> d;
        x--, y--;
        x = -(x - tmp);
        robot tmp;
        tmp.x = x, tmp.y = y;
        if(d == 'N') tmp.direction = 0;
        else if(d == 'E') tmp.direction = 1;
        else if(d == 'S') tmp.direction = 2;
        else if(d == 'W') tmp.direction = 3;
        v.push_back(tmp);
        board[x][y] = cnt, cnt++;
    }

    while(M--){
        int idx;
        cin >> idx >> d >> tmp;
        idx--;
        while(tmp--){
            switch (d)
            {
            case 'L':
                v[idx].direction--;
                if(v[idx].direction < 0) v[idx].direction += 4;
                break;
            case 'R':
                v[idx].direction++;
                v[idx].direction %= 4;
                break;
            case 'F':
                board[v[idx].x][v[idx].y] = -1;
                int dx = v[idx].x + direction[v[idx].direction][0];
                int dy = v[idx].y + direction[v[idx].direction][1];
                if(dx < 0 || dx >= B || dy < 0 || dy >= A) {if(str.empty()) str = "Robot " + to_string(idx + 1) + " crashes into the wall"; break;} 
                else if(board[dx][dy] != -1) {if(str.empty()) str = "Robot " + to_string(idx + 1) + " crashes into robot " + to_string(board[dx][dy] + 1); break;}
                v[idx].x = dx, v[idx].y = dy, board[dx][dy] = idx;
                break;
            }
        }
    }
    if(str.empty())cout << "OK";
    else cout << str;
}
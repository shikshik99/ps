#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int, int>

vector <vector<int>> v;
vector <int> answer;
int arr[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
bool chk[51][51];
int w = 1, h = 1;

void BFS(int x, int y){
    queue <pair<int,int>>q;
    pii tmp;
    int dx, dy;
    q.push({x, y}), chk[x][y] = true;
    while(!q.empty()){
        tmp = q.front(), q.pop();
        for(int i = 0; i < 8; i++){
            dx = tmp.first + arr[i][0];
            dy = tmp.second + arr[i][1];
            if(dx < 0 || dy < 0 || dx >= h || dy >= w ||chk[dx][dy] || !v[dx][dy]) continue;
            q.push({dx,dy}), chk[dx][dy] = true;
        }
    }
}

int main(){
    int tmp = 0, cnt;
    cin >> w >> h;
    while(w||h){
        cnt = 0;
        v.clear(), v.resize(h);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) cin >> tmp, v[i].push_back(tmp);
        }
        memset(chk, 0, sizeof(chk));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(chk[i][j] || !v[i][j]) continue;
                BFS(i, j), cnt++;
            }
        }
        answer.push_back(cnt);
        cin >> w >> h;
    }

    for(auto it : answer) cout << it << '\n';
}
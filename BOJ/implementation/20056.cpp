#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct fireball{
    int r = -1, c = -1, m = 0, s = 0, d = 0;
};

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector <fireball> info;
vector <vector<vector<int>>> v;
int N, M, K;

void del(fireball &fire){
    fire.r = -1, fire.c = -1, fire.m = 0, fire.s = 0, fire.d = 0;
}

void move(){
    for(int i = 0; i < info.size(); i++){
        if(info[i].r == -1 || info[i].c == -1) continue;
        int dx = (info[i].r + dir[info[i].d][0] * info[i].s);
        int dy = (info[i].c + dir[info[i].d][1] * info[i].s);
        while(dx < 0) dx += N;
        while(dy < 0) dy += N;
        while(dx >= N) dx -= N;
        while(dy >= N) dy -= N;
        info[i].r = dx, info[i].c = dy;
    }
}

void merge(int x, int y){
    vector <int>tmp;
    for(int i = 0; i < v[x][y].size(); i++) tmp.push_back(v[x][y][i]);
    int idx = tmp[0];
    int flag = info[idx].d % 2;
    bool fla = false;
    for(int i = 1; i < tmp.size(); i++){
        info[idx].m += info[tmp[i]].m, info[idx].s += info[tmp[i]].s;
        if(info[tmp[i]].d % 2 != flag) fla = true;
        del(info[tmp[i]]);
    }
    if(info[idx].m < 5) {del(info[tmp[0]]); return;}
    int cnt = 3;
    int dir;
    int weight = info[idx].m/5;
    int speed = info[idx].s/tmp.size();
    if(fla) dir = 3;
    else dir = 2;
    while(cnt--){
        fireball fire;
        fire.r = x, fire.c = y, fire.m = weight, fire.s = speed, fire.d = dir, dir += 2;
        info.push_back(fire);
    }
    cnt = 0;
    info[tmp[0]].d = dir%2, info[tmp[0]].m = info[tmp[0]].m/5, info[tmp[0]].s = info[tmp[0]].s/tmp.size();
}

int main(){
    int r, c, m, s, d;
    cin >> N >> M >> K;
    v.resize(N);
    for(int i = 0; i < N; i++) v[i].resize(N);
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        r--; c--;
        fireball fire;
        fire.r = r, fire.c = c, fire.m = m, fire.s = s, fire.d = d;
        info.push_back(fire);
    }
    int cnt = 1;
    while(K--){
        move();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) v[i][j].clear();
        }
        for(int i = 0; i < info.size(); i++) {
            if(info[i].r != -1 && info[i].c != -1) v[info[i].r][info[i].c].push_back(i);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                
                if(v[i][j].size() > 1) merge(i, j);
            }
        }
    }
    
    long long answer = 0;
    for(auto it : info) answer += it.m;
    cout << answer;
}
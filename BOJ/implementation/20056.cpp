#include <iostream>
#include <vector>
using namespace std;

struct fireball{
    int r = -1, c = -1, m = 0, s = 0, d = 0;
};

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector <fireball> info;
vector <vector<vector<int>>> v;
int N, M, K;

int main(){
    int r, c, m, s, d;
    cin >> N >> M >> K;
    v.resize(N), info.resize(N * N);
    for(int i = 0; i < N; i++) v[i].resize(N);
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        r--; c--;
        info[i].r = r, info[i].c = c, info[i].m = m, info[i].s = s, info[i].d = d;
    }
}
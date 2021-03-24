#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <string>v, answer;
vector <vector<bool>>chk;
int arr[4][2]= {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int N, M; 

void flooded(int x, int y){
    int cnt = 0, dx, dy;
    if(x == 0) cnt++;
    if(y == 0) cnt++;
    if(x == N - 1) cnt++;
    if(y == M - 1) cnt++;
    for(int i = 0; i < 4; i++){
        dx = x + arr[i][0], dy = y + arr[i][1];
        if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
        if(v[dx][dy] == '.') cnt++;
    }
    if(cnt >= 3) chk[x][y] = true;
}

void after_flooded(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(chk[i][j]) v[i][j] = '.';
        }
    }
}

void new_map(){
    pii a = {-1, -1}, b = {-1, -1}, c = {-1, -1}, d = {-1, -1};
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 'X') {a.first = i, a.second = j; break;}
        }
        if(a.first != -1) break;
    }
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 'X') {b.first = i, b.second = j; break;}
        }
        if(b.first != -1) break;
    }
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){
            if(v[i][j] == 'X') {c.first = i, c.second = j; break;}
        }
        if(c.first != -1) break;
    }
    for(int j = M - 1; j>=0; j--){
        for(int i = 0; i < N; i++){
            if(v[i][j] == 'X') {d.first = i, d.second = j; break;}
        }
        if(d.first != -1) break;
    }
    int ix = min({a.first, b.first, c.first, d.first}), fx = max({a.first, b.first, c.first, d.first}), iy = min({a.second, b.second, c.second, d.second}), fy = max({a.second, b.second, c.second, d.second});
    answer.resize(fx - ix + 1);
    int cnt = 0;
    if(ix == -1) return;
    if(a == b && a == c && a == d && b == c && b == d && c == d) {answer[0].push_back('X'); return;}
    for(int i = ix; i <= fx; i++){
        for(int j = iy; j <= fy; j++){
            answer[cnt].push_back(v[i][j]);
        }
        cnt++;
    }
}

int main(){
    cin >> N >> M;
    v.resize(N), chk.resize(N);
    for(int i = 0; i < N; i++) chk[i].resize(M, false), cin >> v[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) flooded(i, j);
    }
    after_flooded();
    new_map();
    for(auto it : answer) cout << it << '\n';
}
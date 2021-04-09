#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int arr[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
deque <pii> dq;
vector <vector<int>>v;
map <int, char> m;

int main(){ 
    int N, K, x, y, direction = 0, cnt = 1;
    char a;
    cin >> N >> K;
    v.resize(N);
    for(int i = 0; i < N; i++) v[i].resize(N, 0);
    for(int i = 0; i < K; i++) cin >> x >> y, v[x-1][y-1] = 1;

    cin >> K;
    for(int i = 0; i < K; i++) cin >> x >> a, m[x] = a;

    x = y = 0, dq.push_front({x, y});
    deque<pii>::iterator it;
    while(x < N && y < N && x >= 0 && y >= 0){
        x += arr[direction][0], y += arr[direction][1];

        for(auto it : dq){
            if(it.first == x && it.second == y) {cout << cnt; return 0;}
        }
        
        if(x < N && y < N && x >= 0 && y >= 0){
            if(v[x][y]) dq.push_front({x,y}), v[x][y] = 0;
            else dq.push_front({x,y}), dq.pop_back();
        }
        if(m[cnt] == 'L'){
            direction--;
            if(direction < 0) direction += 4;
        }
        else if(m[cnt] == 'D') direction += 1, direction %= 4;
        cnt++;
    }

    cout << cnt-1;
}
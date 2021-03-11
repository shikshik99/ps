#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define pii pair<int, int>

int N, K, ans = 0, ans_cnt = 0;

void BFS(){
    queue <int>q;
    int tmp, chk[100001];
    memset(chk, 0, sizeof(chk));
    q.push(N);
    while(!q.empty()){
        tmp = q.front(), q.pop();
        if(tmp == K) {ans_cnt = chk[tmp]; return;}
        if(tmp - 1 >= 0 && !chk[tmp - 1]) chk[tmp - 1] = chk [tmp] + 1, q.push(tmp - 1);
        if(tmp + 1 <= 100000 && !chk[tmp + 1]) chk[tmp + 1] = chk[tmp] + 1, q.push(tmp + 1);
        if(tmp * 2 <= 100000 && !chk[tmp * 2]) chk[tmp * 2] = chk[tmp] + 1, q.push(tmp*2);
    }
}

void ABFS(){
    queue <pii>q;
    pii tmp;
    bool chk[100001];
    memset(chk, 0, sizeof(chk));
    q.push({N, 0});
    while(!q.empty()){
        tmp = q.front(), q.pop(), chk[tmp.first] = true;
        if(tmp.first == K && ans_cnt == tmp.second) ans++;
        if(tmp.first - 1 >= 0 && !chk[tmp.first - 1]) {
            q.push({tmp.first - 1, tmp.second + 1});
        }
        if(tmp.first + 1 <= 100000 && !chk[tmp.first + 1]) {
            q.push({tmp.first + 1, tmp.second + 1});
        }
        if(tmp.first * 2 <= 100000 && !chk[tmp.first * 2]){
            q.push({tmp.first * 2, tmp.second + 1});
        }
    }
}

int main(){
    cin >> N >> K;
    BFS();    
    ABFS();
    cout << ans_cnt << '\n' << ans;
}
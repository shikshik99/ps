#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C, K, ans = 0;
vector <string>v;
string tmp;
bool chk[5][5] = {false};

void foo(int a, int b, int cnt){
    int arr[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    if(cnt == K && a == 0 && b == C - 1) {ans++; return;}
    if(cnt == K) return;
    for(int i = 0; i < 4; i++){
        int aa = a + arr[i][0];
        int bb = b + arr[i][1];
        if(aa < 0 || aa >= R || bb < 0 || bb >= C || v[aa][bb] == 'T' || chk[aa][bb]) continue;
        chk[aa][bb] = true;
        foo(aa,bb,cnt+1);
        chk[aa][bb] = false;
    }
}

int main(){
    cin >> R >> C >> K;
    v.resize(R);
    for(int i = 0; i < R; i++) cin >> v[i];
    chk[R-1][0] = true;
    foo(R-1,0,1);
    cout << ans;
}
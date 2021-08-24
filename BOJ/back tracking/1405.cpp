#include <iostream>
#define MAX 31
using namespace std;

int arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
double per[4];
bool chk[MAX][MAX] = {false, };
int re;

double DFS(int x, int y, int cnt){
    if(chk[x][y]) return 0;
    if(!cnt) return 1;
    
    double ret = 0;
    chk[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int dx = x + arr[i][0];
        int dy = y + arr[i][1];
        if(dx < 0 || dx >= MAX || dy < 0 || dy >= MAX) continue;
        ret += (DFS(dx, dy, cnt - 1) * per[i]);
    }

    chk[x][y] = false;

    return ret;
}

int main(){
    cin >> re;
    for(int i = 0; i < 4;i ++) cin >> per[i], per[i] /= 100;
    
    cout.precision(15);
    cout << DFS(MAX / 2, MAX / 2, re) << '\n';
}
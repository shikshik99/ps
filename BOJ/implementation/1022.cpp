#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int arr[50][5];
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int r1, r2, c1, c2; 

void draw(){
    int direction = -1, cnt = 1, inc = 0, i = 1;
    int x = 5000, y = 5000;
    while(1){
        direction++; direction %= 4;
        int tmp = cnt;
        while(tmp--){
            if(x < 0 || x > 10000 || y < 0 || y > 10000) break;
            if((x >= r1 && x <= r2) && (y <= c2 && y >= c1)) arr[abs(x - r1)][abs(y - c1)] = i;
            x = dir[direction][0] + x;
            y = dir[direction][1] + y;
            i++;
        }
        if(x < 0 || x > 10000 || y < 0 || y > 10000) break;
        inc++; inc%=2;
        if(!inc) cnt++;
    }
}

int digit(int num){
    int cnt = 0;
    while(num) num /= 10, cnt++;
    return cnt;
}

int main(){
    memset(arr, 0, sizeof(arr));
    int max = 0, max_cnt;
    cin >> r1 >> c1 >> r2 >> c2;
    int ii = r2 - r1, jj = c2 - c1;
    r1 = 5000 + r1, c1 = 5000 + c1;
    r2 = 5000 + r2, c2 = 5000 + c2;
    draw();
    for(int i = 0; i <= ii; i++){
        for(int j = 0; j <= jj; j++){
            max = max > arr[i][j] ? max : arr[i][j];
        }
    }
    max_cnt = digit(max);
    int tmp;
    for(int i = 0; i <= ii; i++){
        for(int j = 0; j <= jj; j++){
            tmp = max_cnt - digit(arr[i][j]);
            while(tmp--) cout << ' ';
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
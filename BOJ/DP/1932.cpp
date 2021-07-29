#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int D[MAX][MAX];
int N;

int foo(int x, int y){
    if( x == N - 1 ) return arr[x][y];

    int &ret = D[x][y];
    if(ret != -1) return ret;
    ret = arr[x][y];

    ret = max(foo(x + 1, y), foo(x + 1, y + 1)) + ret;

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i + 1; j++){
            cin >> arr[i][j];
        }
    }

    cout << foo(0,0);
}
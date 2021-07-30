#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x6f6f6f6f
using namespace std;

int W[17][17];
int D[17][65537];
int N, start = 0;

int TSP(int current, int visit){
    if(visit == (1 << N) - 1) return W[current][start] ? W[current][start] : INF;
    int &ret = D[current][visit];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < N; i++){
        if(visit & (1 << i)) continue;
        if(!W[current][i]) continue;
        ret = min(ret, W[current][i] + TSP(i, visit | (1 << i)));
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> W[i][j];
    }

    memset(D, -1, sizeof(D));
    cout << TSP(0, 1);
}
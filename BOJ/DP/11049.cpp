#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 501
#define INF 0x7f7f7f7f
using namespace std;
using pii = pair<int, int>;

vector <pii> v;
int D[MAX][MAX];
int N;

int foo(int start, int end){
    if(start == end) return 0;
    int &ret = D[start][end];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = start; i < end; i++){
        int left = foo(start, i);
        int right = foo(i + 1, end);  
        ret = min(ret, left + right + (v[start].first * v[i].second * v[end].second));
    }

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    int r, c;

    for(int i = 0; i < N; i++) cin >> r >> c, v.push_back({r,c});
    
    cout << foo(0, N - 1);
}
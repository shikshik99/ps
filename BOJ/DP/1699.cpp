#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 317
using namespace std;

int D[MAX][100001], arr[MAX];

bool cmp(int a, int b){
    return a > b ? true : false;
}

int foo(int idx, int val){
    if(!val) return 0;
    if(idx == MAX - 1) return val;

    int &ret = D[idx][val];
    if(ret != -1) return ret;
    ret = foo(idx + 1, val);
    if(val >= arr[idx]) ret = min(ret, foo(idx, val - arr[idx]) + 1);

    return ret;
}

int main(){
    memset(D, -1, sizeof(D));
    int N;
    cin >> N;
    for(int i = 1; i <= MAX; i++){
        arr[i - 1] = i * i;
    }
    sort(arr, arr + MAX, cmp);

    cout << foo(0, N);
}
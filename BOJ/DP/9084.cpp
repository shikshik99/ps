#include <iostream>
#include <cstring>
using namespace std;

int arr[21];
int D[21][10001];
int N;

int foo(int num, int cost){
    if(!cost) return 1;
    if(num == N) return 0;

    int &ret = D[num][cost];
    if(ret != -1) return ret;

    ret = foo(num + 1, cost);
    if(cost - arr[num] >= 0) ret += foo(num, cost - arr[num]);

    return ret;
}

int main(){
    int M, T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> arr[i];
        cin >> M;
        memset(D, -1, sizeof(D));
        cout << foo(0, M) << '\n';
    }
}
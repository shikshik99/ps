#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int D[MAX][3];
int arr[2][MAX];
int T, N;

int foo(int idx, int left){
    if(idx == N) return 0;
    
    int &ret = D[idx][left];
    if(ret != -1) return ret;
    ret = foo(idx + 1, 0);

    if(left != 1) ret = max(ret, foo(idx + 1, 1) + arr[0][idx]);
    if(left != 2) ret = max(ret, foo(idx + 1, 2) + arr[1][idx]);

    return ret;
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }
        memset(D, -1, sizeof(D));

        cout << foo(0, 0) << '\n';
    }
}  
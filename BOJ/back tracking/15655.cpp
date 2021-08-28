#include <iostream>
#include <algorithm>
using namespace std;

bool chk[9] = {false, };
int arr[9];
int N, M;

void foo(int idx, int depth){
    if(depth == M){
        for(int i = 0; i < N; i++) {
            if(chk[i]) cout << arr[i] << ' ';
        }
        cout << '\n'; return;
    }

    for(int i = idx + 1; i < N; i++){
        chk[i] = true;
        foo(i, depth + 1);
        chk[i] = false;
    }

}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    foo(-1, 0);
}
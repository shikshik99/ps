#include <iostream>
using namespace std;

bool chk[9] = {false, };
int N, M;

void foo(int idx, int depth){
    if(depth == M){
        for(int i = 1; i <= N; i++){
            if(chk[i]) cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx + 1; i <= N; i++){
        chk[i] = true;
        foo(i, depth + 1);
        chk[i] = false;
    }
}

int main(){
    cin >> N >> M;
    foo(0, 0);
}
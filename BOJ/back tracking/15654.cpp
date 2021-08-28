#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[9] = {false, };
vector <int> v, arr;
int N, M;

void foo(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++) cout << v[i] << ' ';
        cout << '\n'; return;
    }

    for(int i = 0; i < N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        v.push_back(arr[i]);
        foo(depth + 1);
        v.pop_back();
        chk[i] = false;
    }
}

int main(){
    cin >> N >> M;
    int tmp;
    for(int i = 0; i < N; i++) cin >> tmp, arr.push_back(tmp);
    sort(arr.begin(), arr.end());
    foo(0);
}
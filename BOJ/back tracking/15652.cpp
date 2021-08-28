#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int N, M;

void foo(int idx, int depth){
    if(depth == M){
        for(int i = 0; i < M; i++) cout << v[i] << ' ';
        cout << '\n'; return;
    }

    for(int i = idx; i <= N; i++){
        v.push_back(i);
        foo(i, depth + 1);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M;
    foo(1, 0);
}
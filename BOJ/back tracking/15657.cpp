#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[9];
int N, M;
vector <int> v;

void foo(int idx, int depth){
    if(depth == M){
        for(int i = 0; i < M; i++) cout << v[i] << ' ';
        cout << '\n'; return;
    }

    for(int i = idx; i < N; i++){
        v.push_back(arr[i]);
        foo(i, depth + 1);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    foo(0, 0);
}
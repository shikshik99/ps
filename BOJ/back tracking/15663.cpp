#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[9];
int arr[9];
int N, M;
vector <int> v;
vector <vector <int>> answer;

void foo(int depth){
    if(depth == M){
        answer.push_back(v);
        return;
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
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    foo(0);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for(int i = 0; i < answer.size(); i++){
        for(auto it : answer[i]) cout << it << ' ';
        cout << '\n';
    }
}
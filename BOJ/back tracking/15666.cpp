#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[9];
int N, M;
vector <int> v;
vector <vector<int>> answer;

void foo(int idx, int depth){
    if(depth == M){
        answer.push_back(v);
        return;
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
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for(int i = 0; i < answer.size(); i++){
        for(int it : answer[i]) cout << it << ' ';
        cout << '\n';
    }
}
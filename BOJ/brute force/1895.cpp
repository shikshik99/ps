#include <bits/stdc++.h>
#define MAX 41
using namespace std;

int board[MAX][MAX];
int N, M, T;

int solve(int x, int y){
    vector <int> v;
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            v.push_back(board[i][j]);
        }
    }
    sort(v.begin(), v.end());

    if(v[4] >= T) return 1;
    return 0;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> board[i][j];
    }
    cin >> T;
    
    int answer = 0;
    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++) answer += solve(i, j);
    }
    
    cout << answer << '\n';
}
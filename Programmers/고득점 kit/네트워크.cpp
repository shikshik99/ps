#include <bits/stdc++.h>
#define MAX 201
using namespace std;

bool chk[MAX];
int board[MAX][MAX];
int N;

void BFS(int a){
    queue <int> q;
    chk[a] = true;
    q.push(a);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i = 0; i < N; i++){
            if(chk[i] || !board[num][i]) continue;
            q.push(i);
            chk[i] = true;
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    N = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = computers[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!chk[i]) BFS(i), answer++;
    }
    
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <functional>
using namespace std;
#define pii pair<int, int>

vector <vector<deque<int>>> board;
vector <vector<int>> A;
vector <vector<int>> land;
int arr[8][2] = {{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int N, M, K;

bool cmp(pii A, pii B){
    if(A.first < B.first) return true;
    return false;
}

void spring(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j].empty()) continue;
            for(int k = board[i][j].size() - 1; k >= 0; k--){
                if(board[i][j][k] > land[i][j]){
                    for(int x = 0; x <= k; x++){
                        land[i][j] += (board[i][j][x]/2);
                    }
                    for(int x = 0; x <= k; x++){
                        board[i][j].pop_front();
                    }
                    break;
                }
                else land[i][j] -= board[i][j][k], board[i][j][k] += 1;
            }
        }
    }
}

void fall(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j].empty()) continue;
            for(auto it : board[i][j]){
                if(!(it%5)){
                    for(int k = 0; k < 8; k++){
                        int dx = i + arr[k][0];
                        int dy = j + arr[k][1];
                        if(dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
                        board[dx][dy].push_back(1);
                    }
                }
            }
        }
    }    
}

void winter(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            land[i][j] += A[i][j];
        }
    }
}

int main(){
    cin >> N >> M >> K;
    A.resize(N), land.resize(N), board.resize(N);
    for(int i = 0; i < N; i++) A[i].resize(N, 0), land[i].resize(N, 5), board[i].resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    while(M--){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        board[x][y].push_back(z);
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j].empty()) continue;
            sort(board[i][j].begin(), board[i][j].end(), greater<>());
        }
    }
    
    while(K--){
        spring();
        fall();
        winter();
    }

    int answer = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j].empty()) continue;
            answer += board[i][j].size();
        }
    }
    cout << answer;
}
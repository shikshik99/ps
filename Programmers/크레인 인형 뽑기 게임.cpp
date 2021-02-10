#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector <stack<int>> v;
stack <int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    v.resize(board.size());
    for(int i = board.size() - 1; i >= 0; i--){
        for(int j = 0; j < board[i].size(); j++){
            if(!board[i][j]) continue;
            v[j].push(board[i][j]);
        }
    }
    for(int i = 0; i < moves.size(); i++){
        if(v[moves[i]-1].empty()) continue;
        if(s.empty()) s.push(v[moves[i]-1].top()), v[moves[i]-1].pop();
        else if(!s.empty() && v[moves[i]-1].top() == s.top()) s.pop(), v[moves[i]-1].pop(), answer++;
        else if(!s.empty() && v[moves[i]-1].top() != s.top()) s.push(v[moves[i]-1].top()), v[moves[i]-1].pop();
    }
    return answer * 2;
}
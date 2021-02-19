#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> v;
int N, answer = 0;

int foo(int x, int y){
    int cnt = 0, tmp = 1;
    for(int i = 0; i < N; i++){
        tmp = 1;
        for(int j = 0; j < N - 1; j++){
            if(v[i][j] == v[i][j+1]) tmp++;
            if(v[i][j] != v[i][j+1]) cnt = max(cnt, tmp), tmp = 1;
        }
        cnt = max(cnt, tmp);
    }
    for(int i = 0; i < N; i++){
        tmp = 1;
        for(int j = 0; j < N - 1; j++){
            if(v[j][i] == v[j+1][i]) tmp++;
            if(v[j][i] != v[j+1][i]) cnt = max(cnt, tmp), tmp = 1;
        }
        cnt = max(cnt, tmp);
    }
    
    return max(cnt, tmp);
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < v[i].length(); j++){
            if(i + 1 < N) swap(v[i][j], v[i+1][j]), answer = max(answer,  foo(i, j)), swap(v[i][j], v[i+1][j]);
            if(j + 1 < v[i].length()) swap(v[i][j+1], v[i][j]), answer = max(answer,  foo(i, j)),swap(v[i][j+1], v[i][j]);
        }
    }   
    cout << answer;
}
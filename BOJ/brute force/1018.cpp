#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7f7f7f7f;
using namespace std;

vector <string> v;
int N, M;

int foo(int x, int y, char ch){
    int ret = 0;
    char ch2 = 'B';
    if(ch == 'B') ch2 = 'W';
    
    for(int i = x; i < x + 8; i++){
        for(int j = y; j < y + 8; j++){
            if(v[i][j] != ch) ret++;
            swap(ch, ch2);
        }
        swap(ch, ch2);
    }
    return ret;
}

int main(){
    string str;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(str);
    }
    
    int answer = INF;
    for(int i = 0; i < N - 7; i++){
        for(int j = 0; j < M - 7; j++){
            answer = min(answer, foo(i, j, 'B'));
            answer = min(answer, foo(i, j, 'W'));
        }
    }

    cout << answer << '\n';
}
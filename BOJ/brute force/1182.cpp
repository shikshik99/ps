#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> v;
bool chk[20];

int foo(int depth, int target, int start, int S){
    int answer = 0;
    if(depth == target){
        int tmp = 0;
        for(int i = 0; i < v.size(); i++){
            if(chk[i]) tmp += v[i];
        }
        if(tmp == S) return 1;
        return 0;
    }
    for(int i = start; i < v.size(); i++){
        chk[i] = true;
        answer += foo(depth + 1, target, i + 1, S);
        chk[i] = false;
    }
    return answer;
}

int main(){
    int N, S;
    int answer = 0;
    cin >> N >> S;
    v.resize(N);
    for(int i = 0 ; i < N; i++) cin >> v[i];
    for(int i = 1; i <= v.size(); i++){
        memset(chk, false, sizeof(chk));
        answer += foo(0, i, 0, S);
    }
    cout << answer;
}
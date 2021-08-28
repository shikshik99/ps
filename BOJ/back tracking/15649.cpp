#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
bool chk[9] = {false, };
int N, M;

void foo(int depth){
    if(depth == M){
        for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << '\n'; return;
    }

    for(int i = 1; i <= N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        v.push_back(i);
        foo(depth + 1);
        v.pop_back();
        chk[i] = false;
    }
}

int main(){
    cin >> N >> M;
    foo(0);
}
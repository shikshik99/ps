#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
vector <int> in;
vector <int> answer;

void foo(int num){
    for(int a = 0; a < 45; a++){
        for(int b = 0; b < 45; b++){
            for(int c = 0; c < 45; c++){
                if(v[a]+v[b]+v[c] == num) {answer.push_back(1); return;}
            }
        }
    }
    answer.push_back(0);
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i < 46; i++) v.push_back(i*(i+1)/2);
    in.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> in[i];
        foo(in[i]);
    }
    for(auto it : answer) cout << it << '\n';
}
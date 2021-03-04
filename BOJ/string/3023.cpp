#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string>v;

int main(){
    int R, C, A, B;
    cin >> R >> C;
    v.resize(R);
    for(int i = 0; i < R; i++) cin >> v[i];
    cin >> A >> B;
    for(int i = 0; i < R; i++){
        for(int j = C - 1; j >= 0; j--){
            v[i] += v[i][j];
        }
    }
    for(int i = R - 1; i >= 0; i--) v.push_back(v[i]);
    if(v[A - 1][B - 1] == '.') v[A - 1][B - 1] = '#';
    else v[A - 1][B - 1] = '.';
    for(auto it : v) cout << it << '\n';
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string>v;

int main(){
    int A, B, R, C;
    cin >> R >> C >> A >> B;
    v.resize(R*A);
    for(int i = 0; i < R * A; i++){
        for(int j = 0; j < C * B; j++){
            if((i/A)%2 == 0 && (j/B)%2 == 0) v[i] += 'X';
            else if((i/A)%2 == 1 && (j/B)%2 == 1) v[i] += 'X';
            else if((i/A)%2 == 1 && (j/B)%2 == 0) v[i] += '.';
            else if((i/A)%2 == 0 && (j/B)%2 == 1) v[i] += '.';
        }
    }
    for(auto it : v) cout << it <<'\n';
}
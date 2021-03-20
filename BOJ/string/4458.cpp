#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string>v;

int main(){
    int N;
    cin >> N;
    cin.ignore();
    v.resize(N);
    for(int i = 0; i < N; i++) getline(cin, v[i]);
    for(int i = 0; i < N; i++){
        if(v[i][0] >= 97 && v[i][0] <= 97+26) v[i][0] -= (97 - 65);
    }
    for(auto it : v) cout << it << '\n';
}
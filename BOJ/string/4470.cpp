#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string>v;

int main(){
    int N, i;
    cin >> N;
    cin.ignore();
    v.resize(N);
    for(i = 0 ; i < N; i++) getline(cin, v[i]);
    i = 1;
    for(auto it : v) cout << i++ << ". " << it << '\n';
}
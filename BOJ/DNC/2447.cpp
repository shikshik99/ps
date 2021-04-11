#include <iostream>
#include <vector>
#include <string>
using namespace std;
    
int N;
vector <string>v;

void DNC(int x, int y, int size){
    int nsize = size/3;
    if(size > 3){
    for(int i = x; i < x + size; i += nsize){
        for(int j = y; j < y + size; j += nsize){
            DNC(i, j, nsize);
        }
    }
    }
    for(int i = x + nsize; i < x + nsize * 2; i++){
        for(int j = y + nsize; j < y + nsize * 2; j++){
            v[i][j] = ' ';
        }
    }
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)v[i].resize(N, '*');
    DNC(0,0,N);
    for(auto it : v) cout << it << '\n';
}
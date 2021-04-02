#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <vector<int>>v;
map <int, int> m;
int N;

void devide(int x, int y, int size){
    int pivot = v[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(v[i][j] != pivot) {
                int div = size / 3;
                for(int a = x; a < x + size; a += div){
                    for(int b = y; b < y + size; b += div){
                        devide(a,b,div);
                    }
                }
                return;
            }
        }
    }
    m[pivot]++;
}

int main(){
    m[-1] = 0, m[0] = 0, m[1] = 0;
    cin >> N;
    cin.ignore();
    v.resize(N);
    for(int i = 0; i < N; i++){
        v[i].resize(N);
        for(int j = 0; j < N; j++) cin >> v[i][j];
    }
    devide(0, 0, N);
    for(auto it : m) cout << it.second << '\n';
}
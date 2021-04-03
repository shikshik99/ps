#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <vector<int>>v;
vector <int> answer;
int N;

void DAC(int x, int y, int level){
    int size = N >> level;
    int pivot = v[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(pivot != v[i][j]){
                cout << '(';
                int nsize = N >> (level + 1);
                for(int a = x; a < x + size; a += nsize){
                    for(int b = y; b < y + size; b += nsize){
                        DAC(a, b, level + 1);
                    }
                }
                cout << ')';
                return ;
            }
        }
    }
    cout << pivot;
}

int main(){
    cin >> N;
    string str;
    v.resize(N);
    for(int i = 0; i < N; i++){
        v[i].resize(N), cin >> str;
        for(int j = 0; j < N; j++) v[i][j] = str[j]-'0';
    }    
    DAC(0,0,0); 
}
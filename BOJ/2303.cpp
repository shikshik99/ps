#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>>v;
vector <int>tmp;
int N;

int foo(){
    int ans = 0;
    int aa;
    for(int i = 0; i < N; i++){
        aa = 0;
        for(int a = 0; a < 3; a++){
            for(int b = a + 1; b< 4; b++){
                for(int c = b+1; c < 5; c++){
                    aa = max(aa, (v[i][a]+v[i][b]+v[i][c])%10);
                }
            }
        }
        tmp.push_back(aa);
    }
    for(int i = 1; i < N; i++){
        ans = tmp[ans] > tmp[i] ? ans : i;
    }

    return ans + 1;
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        v[i].resize(5);
        for(int j = 0; j < 5; j++){
            cin >> v[i][j];
        }
    }
    cout << foo();
}
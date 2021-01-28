#include <iostream>
#include <string>
using namespace std;

string squa[51];

int main(){
    int N, M, ans=0, a=0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        squa[i].reserve(51);
        cin >> squa[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = j; k < M; k++){
                if(i+k-j < N){
                if(squa[i][j] == squa[i][k] && squa[i][j] == squa[i+k-j][j] && squa[i][j] == squa[i+k-j][k]){
                    if(ans < (k-j+1)*(k-j+1)) ans = (k-j+1)*(k-j+1);
                }
                }
            }
        }
    }
    cout << ans;
}
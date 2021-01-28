#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double stu[2][7] = {0};

int main(){
    double K;
    int N, a, b, ans=0;
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> a >> b;
        stu[a][b]++;
    }
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 1 ; j < 7; j++){
            ans = ans + ceil(stu[i][j]/K);
        }
    }
    cout<<ans;
}
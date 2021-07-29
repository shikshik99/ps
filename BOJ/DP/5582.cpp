#include <iostream>
#include <cstring>
#include <string>
#define MAX 4001
using namespace std;

int D[MAX][MAX];
string A, B;

int main(){
    memset(D, 0, sizeof(D));

    cin >> A >> B;
    int ans = 0;
    for(int i = 1; i <= A.length(); i++){
        for(int j = 1; j <= B.length(); j++){
            if(A[i - 1] == B[j - 1]) D[i][j] = (D[i- 1][j-1] + 1);
            ans = ans > D[i][j] ? ans : D[i][j];
        }
    }

    cout << ans << '\n';
}
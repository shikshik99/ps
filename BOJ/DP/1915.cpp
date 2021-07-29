#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int D[MAX][MAX];
int N, M, ans = 0;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;

    char ch;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> ch;
            D[i][j] = (ch - '0');
            if(D[i][j]) D[i][j] += min(min(D[i - 1][j], D[i-1][j-1]) , D[i][j-1]);
            ans = max(ans, D[i][j]);
        }
    }
    
    cout << ans * ans << '\n';
}
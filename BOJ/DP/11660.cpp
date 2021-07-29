#include <iostream>
#include <cstring>
#define MAX 1025
using namespace std;

int arr[MAX][MAX];
int D[MAX][MAX];
int N, M;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(D, 0, sizeof(D));
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            D[i][j] = arr[i][j] + D[i][j - 1];
        }
    }   

    int x1, y1, x2, y2;
    while(M--){
        int answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++){
            answer += (D[i][y2] - D[i][y1 - 1]);
        } 
        cout << answer << '\n';
    }
}
#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int N, M;

int main(){
    cin >> N >> M;
    int u, v;
    while(M--){
         cin >> u >> v;
         u -= 1, v -= 1;
         arr[u][v] = 1;
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][k] && arr[k][j]) arr[i][j] = 1;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(arr[i][j]) cnt++;
            if(arr[j][i]) cnt++;
        }
        if(cnt == N - 1) answer++;
    }

    cout << answer << '\n';
}
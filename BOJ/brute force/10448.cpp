#include <iostream>
#define MAX 46
using namespace std;

int arr[MAX];
int T, K;

int solve(){
    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < MAX; j++){
            for(int k = 1; k < MAX; k++){
                if(arr[i] + arr[j] + arr[k] == K) return 1;
            }
        }
    }
    
    return 0;
}

int main(){
    cin >> T;
    for(int i = 1; i < MAX; i++) arr[i] = (i * (i + 1)) / 2;
    while(T--){
        cin >> K;
        cout << solve() << '\n';
    }
}
#include <iostream>
#include <cmath>
using namespace std;

bool arr[1001] = {false, };
int N, K;

int main(){
    cin >> N >> K;
    for(int i = 2; i <= N; i++){
        if(arr[i]) continue;
        for(int j = i; j <= N; j += i){
            if(arr[j]) continue;
            K--;
            if(!K) printf("%d\n", j);
            arr[j] = true;
        }
    }
}
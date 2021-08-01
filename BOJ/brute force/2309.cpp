#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

void print_answer(int a, int b){
    for(int i = 0; i < 9; i++) if(i != a && i != b) cout << arr[i] <<'\n';
}

int main(){
    int sum = 0;
    for(int i = 0; i < 9; i++) cin >> arr[i], sum += arr[i];
    sort(arr, arr + 9);

    for(int i = 0; i < 9; i++){
        sum -= arr[i];
        for(int j = i + 1; j < 9; j++){
            if(sum - arr[j] == 100) print_answer(i, j), exit(0);
        }
        sum += arr[i];
    }
}
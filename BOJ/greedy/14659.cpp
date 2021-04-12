#include <iostream>
using namespace std;

int arr[30001];
int N, answer;

void foo(int idx){
    int tmp = arr[idx], cnt = 0;
    for(int i = idx + 1; i < N; i++){
        if(tmp >= arr[i]) cnt++;
        else break;
    }
    answer = answer > cnt ? answer : cnt;
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < N - 1; i++) foo(i);
    cout << answer;
}
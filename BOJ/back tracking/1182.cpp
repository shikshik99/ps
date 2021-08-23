#include <iostream>
#define MAX 21
using namespace std;

int arr[MAX];
int N, S, cnt, sum = 0;

void foo(int cur){
    if(cur == N) return ;

    foo(cur + 1);

    sum += arr[cur];
    if(sum == S) cnt++;
    foo(cur + 1);
    sum -= arr[cur];
}

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];

    foo(0);
    cout << cnt << '\n';
}
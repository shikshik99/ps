#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 0x6f6f6f6f
using namespace std;

int arr[MAX];
int N, M;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int s = 0, e = 0, minus = 0;
    int answer = INF;
    while(s < N){
        if(e == N || minus >= M) s++, minus = arr[e] - arr[s];
        else e++, minus = arr[e] - arr[s];
        if(minus >= M) answer = answer < minus ? answer : minus;
    }

    cout << answer << '\n';
}
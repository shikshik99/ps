#include <iostream>
#define MAX 100001
#define INF 0x6f6f6f6f
using namespace std;

int arr[MAX];
int N, S;

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int s = 0, e = 0, answer = INF;
    int psum = 0;
    while(s < N){
        if(e == N || psum > S) psum -= arr[s++];
        else psum += arr[e++];
        if(psum >= S) answer = answer < e - s ? answer : e - s;
    }

    if(answer == INF) cout << 0 << '\n';
    else cout << answer << '\n';
}
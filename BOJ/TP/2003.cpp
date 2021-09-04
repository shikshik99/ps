#include <iostream>
#define MAX 10001
using namespace std;

int arr[MAX];
int N, M;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int psum = 0, s = 0, e = 0;
    int answer = 0;
    while(s < N){
        if(e == N || psum >= M) {
            psum -= arr[s++];
        }
        else psum += arr[e++];
        if(psum == M) answer++;
    }

    cout << answer << '\n';
}
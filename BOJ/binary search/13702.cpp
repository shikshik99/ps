#include <iostream>
#include <cmath>
#define MAX 10001
using namespace std;

int arr[MAX];
int N, M;

bool possible(int tmp){
    int cnt = 0;
    for(int i = 0; i < N; i++) cnt += (arr[i] / tmp);

    return cnt >= M ? true : false;
}

int main(){
    cin >> N >> M;
    int lo = 0, hi = 0;
    for(int i = 0; i < N; i++) cin >> arr[i], hi = hi > arr[i] ? hi : arr[i];

    if(M == 1) cout << hi << '\n', exit(0);

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }
    
    cout << lo << '\n';
}
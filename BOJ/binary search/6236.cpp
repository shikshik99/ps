#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int N, M;

bool possible(int tmp){
    int cnt = 0, sum = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] > tmp) return true;
        if(sum + arr[i] > tmp) cnt++, sum = arr[i];
        else sum += arr[i];
    }

    return cnt >= M ? true : false;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int lo = 0, hi = MAX * 10000;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << hi << '\n';
}
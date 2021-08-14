#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int N, M;

bool possible(int len){
    int cnt = 0;
    int sum = 0;    
    for(int i = 0; i < N; i++){
        if(arr[i] > len) return true;
        if(sum + arr[i] > len) cnt++, sum = arr[i];
        else sum += arr[i];
    }

    return cnt >= M ? true : false;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int lo = 0, hi = 1000000001;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << hi << '\n';
}
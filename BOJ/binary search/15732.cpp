#include <iostream>
#define MAX 10001
using namespace std;
using ll = long long;

int N, K, D;
int A[MAX], B[MAX], C[MAX];

bool possible(int mid){
    ll sum = 0;
    int tmp;
    for(int i = 0; i < K; i++){
        tmp = mid < B[i] ? mid : B[i];
        if(tmp >= A[i]) sum += ((tmp - A[i]) / C[i]) + 1;
    }

    return sum < D ? true : false;
}

int main(){
    cin >> N >> K >> D;

    for(int i = 0; i < K; i++) cin >> A[i] >> B[i] >> C[i];

    int lo = 0, hi = N;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << hi << '\n';
}
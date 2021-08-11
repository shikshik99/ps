#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
using ll = long long;

ll arr[MAX];
int N;

ll foo(int start, int end){
    if(start == end) return 0;
    if(start == end - 1) return arr[start];

    int mid = (start + end) / 2;
    ll ret = max(foo(start, mid), foo(mid + 1, end));

    ll garo = 1, left = mid, right = mid, sero = arr[mid];
    ret = max(ret, sero);
    while(start < left || right < end){
        garo++;
        ll lvalue = arr[left - 1];
        ll rvalue = arr[right + 1];
        if(right < end && (left == start || rvalue >= lvalue)){
            sero = min(sero, arr[++right]);
        }
        else sero = min(sero, arr[--left]);

        ret = max(ret, sero * garo);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    cout << foo(0, N);
}
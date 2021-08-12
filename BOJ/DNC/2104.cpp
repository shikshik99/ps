#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
using ll = long long;

ll arr[MAX];
int N;

ll foo(int start, int end){
    if(start == end) return arr[start] * arr[start];
    
    int mid = (start + end) / 2;
    ll ret = max(foo(start, mid), foo(mid + 1, end));

    int left = mid, right = mid;
    ll psum = arr[mid], minimum = arr[mid];
    while(start < left || right < end){
        ll lvalue = left > start ? arr[left - 1] : -1;
        ll rvalue = right < end ? arr[right + 1] : -1;
        if(rvalue >= lvalue){
            psum += arr[++right];
            minimum = minimum < arr[right] ? minimum : arr[right];
        }
        else{
            psum += arr[--left];
            minimum = minimum < arr[left] ? minimum : arr[left];
        }
        
        ret = max(ret, minimum * psum);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    cout << foo(0, N - 1);
}
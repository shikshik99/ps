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
    
    ll left = mid, right = mid, minimum = arr[mid], psum = arr[mid];
    while(left > start || right < end){
        ll lvalue = arr[left - 1];
        ll rvalue = arr[right + 1];
        if(right < end  && (rvalue >= lvalue || left == start)){
            psum += arr[++right];
            minimum = min(minimum, arr[right]);
        }
        else{
            psum += arr[--left];
            minimum = min(minimum, arr[left]);
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
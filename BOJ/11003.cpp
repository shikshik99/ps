#include <iostream>
#include <deque>
using namespace std;
#define pii pair <int, int>

deque <pii> dq;
int arr[5000001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, L;
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 0; i < N; i++){
        if(dq.empty()) ;
        else {
            if(dq.front().first < i - L + 1) dq.pop_front();
            while(!dq.empty() && dq.back().second > arr[i]) dq.pop_back();
        }
        dq.push_back({i, arr[i]});

        cout << dq.front().second << ' ';
    }
    cout << '\n';
}
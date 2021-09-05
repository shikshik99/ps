#include <iostream>
#include <algorithm>
#define MAX 30001
using namespace std;

int arr[MAX], cnt[3001];
int N, D, K, C;

int main(){
    cin >> N >> D >> K >> C;
    int tmp = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i >= N - K) {
            if(!cnt[arr[i]]) tmp++;
            cnt[arr[i]]++;
        }
    }

    int answer = max(tmp + !cnt[C], answer);
    for(int i = 0; i < N; i++){
        if(!cnt[arr[i]]) tmp++;
        cnt[arr[i]]++;
        cnt[arr[(i + N - K) % N]]--;
        if(!cnt[arr[(i + N - K) % N]]) tmp--;
        answer = max(tmp + !cnt[C], answer);
    }

    cout << answer << '\n';
}
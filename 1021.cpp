#include <iostream>
#include <deque>
using namespace std;

deque <int>dq;

int main(){
    int N, M, ans = 0, a;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) dq.push_back(i);
    for(int i = 0; i < M; i++){
        cin >> a;
        int left, right, tmp, idx = 1;
        for(int j = 0; j < dq.size(); j++){
            if(dq[j] == a) break;
            idx++;
        }
        right = dq.size() - idx + 1;
        left = idx - 1;
        if(left < right){
            for(int j = 0; j < left; j++){
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                ans++;
            }
        }
        else{
            for(int j = 0; j < right; j++){
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                ans++;
            }
        }
        dq.pop_front();
    }
    cout << ans;
}
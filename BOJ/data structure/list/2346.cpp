#include <iostream>
#include <deque>
using namespace std;
using pii = pair<int, int>;

deque <pii> dq;
int N;

void foo(int cnt){
    while(cnt > 0 && cnt--) dq.push_back(dq.front()), dq.pop_front();
    while(cnt < 0 && cnt++) dq.push_front(dq.back()), dq.pop_back();
}

int main(){
    cin >> N;
    int tmp;
    for(int i = 1; i <= N; i++) cin >> tmp, dq.push_back({i, tmp});

    while(!dq.empty()){
        int idx = dq.front().first;
        int cnt = dq.front().second;
        dq.pop_front();
        cout << idx << ' ';
        if(cnt > 0) foo(cnt - 1);
        else foo(cnt);
    }    
}

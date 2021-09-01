#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;
int N;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int tmp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp, pq.push(tmp);
        }
        int cnt = N;
        while(i && cnt--) pq.pop();
    }
    cout << pq.top() << '\n';
}
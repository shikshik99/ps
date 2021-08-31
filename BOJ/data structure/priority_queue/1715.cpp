#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b ? true : false;
    }
};

priority_queue <int, vector<int>, cmp> pq;

int main(){
    int N, tmp;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> tmp, pq.push(tmp);

    int answer = 0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        answer += (A + B);
        pq.push(A + B);
    }
    
    cout << answer << '\n';
}
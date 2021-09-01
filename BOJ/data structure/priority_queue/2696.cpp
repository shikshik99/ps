#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> max_heap;
priority_queue <int, vector<int>, greater<int>> min_heap;

void middle(int N){
    int tmp;
    for(int i = 1; i <= N; i++){
        cin >> tmp;
        if(max_heap.size() <= min_heap.size()) max_heap.push(tmp);
        else min_heap.push(tmp);

        if(!min_heap.empty() && min_heap.top() < max_heap.top()){
            int temp = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(temp);
        }
        if(i % 2) cout << max_heap.top() << ' ';
    }
}

void clear(){
    while(!max_heap.empty()) max_heap.pop();
    while(!min_heap.empty()) min_heap.pop();
}

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << N / 2 + 1 << '\n';
        middle(N);
        clear();
        cout << '\n';
    }
}
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b ? true : false;
        }
        return abs(a) > abs(b) ? true : false;
    }
};

priority_queue <int, vector<int>, cmp> pq;
int N;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int num;
    while(N--){
        cin >> num;
        if(!num) {
            if(pq.empty()) cout << 0 << '\n';
            else cout << pq.top() << '\n', pq.pop();
        }
        else pq.push(num);
    }
}
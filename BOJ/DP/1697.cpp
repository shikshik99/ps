#include <iostream>
#include <queue>
using namespace std;

int N, K, cnt = 0;
queue <int>q1, q2;
bool visit[100001] = {false,};

int main(){
    cin >> N >> K;
    q1.push(N);
    while(1){
        if(!q1.empty()){
            while(!q1.empty()){
                if(q1.front() == K) {cout << cnt; return 0;}
                if(q1.front() * 2 <= 100000 && !visit[q1.front() * 2]) q2.push(q1.front() * 2), visit[q1.front() * 2] = true;
                if(q1.front() + 1 <= 100000 && !visit[q1.front() + 1]) q2.push(q1.front() + 1), visit[q1.front() + 1] = true;
                if(q1.front() - 1 >= 0 && !visit[q1.front() - 1]) q2.push(q1.front() - 1), visit[q1.front() - 1] = true;
                q1.pop();
            }
        }
        else if(!q2.empty()){
            while(!q2.empty()){
                if(q2.front() == K) {cout << cnt; return 0;}
                if(q2.front() * 2 <= 100000 && !visit[q2.front() * 2]) q1.push(q2.front() * 2), visit[q2.front() * 2] = true;
                if(q2.front() + 1 <= 100000 && !visit[q2.front() + 1]) q1.push(q2.front() + 1), visit[q2.front() + 1] = true;
                if(q2.front() - 1 >= 0 && !visit[q2.front() - 1]) q1.push(q2.front() - 1), visit[q2.front() - 1] = true;
                q2.pop();
            }
        }
        cnt++;
    }
}
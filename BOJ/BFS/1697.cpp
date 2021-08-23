#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, K;
bool chk[MAX];

int BFS(){
    queue <int> q;
    q.push(N);
    chk[N] = true;
    
    int ret = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int num = q.front();
            q.pop();
            if(num == K) return ret;
            int jump = num * 2;
            int up = num + 1;
            int down = num - 1;
            if(jump < MAX && !chk[jump]) q.push(jump), chk[jump] = true;
            if(up < MAX && !chk[up]) q.push(up), chk[up] = true;
            if(down >= 0 && !chk[down]) q.push(down), chk[down] = true;
        }

        ret++;
    }
}

int main(){
    cin >> N >> K;
    cout << BFS() << '\n';
}
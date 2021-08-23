#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int N, T, G;
bool chk[MAX] = {false, };

int BFS(){
    queue <int> q;
    q.push(N);
    chk[N] = true;
    
    int ret = 0;
    while(!q.empty()){
        if(chk[G]) return ret;
        int qsize = q.size();
        if(ret == T) break;
        while(qsize--){
            int num = q.front();
            q.pop();
            int A = num + 1;
            if(A < MAX && !chk[A]) q.push(A), chk[A] = true;
            int B = num * 2;
            if(B >= MAX) continue;
            int tmp = 1;
            while(tmp * 10 <= B) tmp *= 10;
            B -= tmp;
            if(B > 0 && !chk[B]) q.push(B), chk[B] = true;
        }
        ret++;
    }

    return -1;
}

int main(){
    cin >> N >> T >> G;
    
    int answer = BFS();
    if(answer == -1) cout << "ANG\n";
    else cout << answer << '\n';
}
#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

bool chk[MAX] = {false, };
int N, S, G, U, D;

int BFS(){
    queue <int> q;
    q.push(S);
    chk[S] = true;

    int ret = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int num = q.front();
            if(num == G) return ret;
            q.pop();
            int up = num + U;
            int down = num - D;
            if(up <= N && !chk[up]) q.push(up), chk[up] = true;
            if(down >= 1 && !chk[down]) q.push(down), chk[down] = true;
        }
        ret++;
    }

    return -1;
}

int main(){
    cin >> N >> S >> G >> U >> D;

    if(S == G) cout << 0 << '\n', exit(0);

    int answer = BFS();
    if(answer == -1) cout << "use the stairs\n";
    else cout << answer << '\n';
}
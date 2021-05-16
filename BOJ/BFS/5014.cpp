#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int, int>

vector <int> ud;
int F, S, G, U, D;
int answer = -1;
bool chk[1000001];

void foo(){
    memset(chk, false, sizeof(chk));
    queue<pii> q;
    q.push({S, 0});
    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        if(tmp.first == G) {answer = tmp.second; return;}
        for(int i = 0; i < 2; i++){
            int level = tmp.first + ud[i];
            int distance = tmp.second + 1;
            if(level <= 0 || level > F || chk[level]) continue;
            q.push({level, distance});
            chk[level] = true;
        }
    }
}

int main(){
    cin >> F >> S >> G >> U >> D;
    ud.push_back(U), ud.push_back(-D);
    foo();
    if(answer == -1) cout << "use the stairs";
    else cout << answer;
}
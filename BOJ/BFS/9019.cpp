#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define MAX 10000
using namespace std;

int pre[MAX];
char ch[MAX];
bool chk[MAX];
int A, B;

int left(int num){
    int D1, D2, D3, D4;
    D4 = num % 10, num /= 10;
    D3 = num % 10, num /= 10;
    D2 = num % 10, num /= 10;
    D1 = num;

    return ((((D2 * 10) + D3) * 10 + D4) * 10 + D1);
}

int right(int num){
    int D1, D2, D3, D4;
    D4 = num % 10, num /= 10;
    D3 = num % 10, num /= 10;
    D2 = num % 10, num /= 10;
    D1 = num;

    return ((((D4 * 10) + D1) * 10 + D2) * 10 + D3);
}

void BFS(){
    queue <int> q;
    chk[A] = true;
    q.push(A);
    
    while(!q.empty()){
        int num = q.front();
        q.pop();

        if(num == B) return;

        int D = num * 2;
        if(D >= MAX) D %= MAX;
        if(!chk[D]) q.push(D), chk[D] = true, pre[D] = num, ch[D] = 'D';
        
        int S = num - 1;
        if(!num) S = 9999;
        if(!chk[S]) q.push(S), chk[S] = true, pre[S] = num, ch[S] = 'S';

        int L = left(num);
        if(!chk[L]) q.push(L), chk[L] = true, pre[L] = num, ch[L] = 'L';

        int R = right(num);
        if(!chk[R]) q.push(R), chk[R] = true, pre[R] = num, ch[R] = 'R';
    }
}

string solve(){
    string ret = "";
    int num = B;
    while(num != A){
        ret += ch[num];
        num = pre[num];
    }

    return ret;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(chk, false, sizeof(chk));
        cin >> A >> B;
        BFS();
        string str = solve();
        int len = str.length();
        for(int i = len - 1; i >= 0; i--) cout << str[i];
        cout << '\n';
    }
}
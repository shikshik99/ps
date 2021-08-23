#include <iostream>
#include <string>
using namespace std;

bool chk[51] = {false, };
int answer[51];
string str;
int N, len;

void print(){
    for(int i = 0; i < N; i++) cout << answer[i] << ' ';
    cout << '\n';
}

void foo(int depth, int idx){
    if(depth == N) print(), exit(0);

    int num = str[idx] - '0';
    if(num > 0 && !chk[num]){
        chk[num] = true;
        answer[depth] = num;
        foo(depth + 1, idx + 1);
        chk[num] = false;
    }

    if(idx < len - 1){
        num = (num * 10) + (str[idx + 1] - '0');
        if(num > 0 && num <= N && !chk[num]){
            chk[num] = true;
            answer[depth] = num;
            foo(depth + 1, idx + 2);
            chk[num] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> str;
    len = str.length();
    for(int i = 0; i < len ; i += (N >= 10 ? 2 : 1)) N++;
    foo(0, 0);
}
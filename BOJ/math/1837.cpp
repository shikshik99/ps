#include <iostream>
#include <string>
#include <cmath>
#define MAX 1000000
using namespace std;
using pii = pair<int, int>;

bool chk[MAX + 1] = {false, };
string P;
int K;

void chk_prime(){
    int len = sqrt(MAX);
    for(int i = 2; i <= len; i++){
        if(chk[i]) continue;
        for(int j = i * 2; j <= MAX; j += i) chk[j] = true;
    }
}

bool divide(int num){
    int len = P.length();
    int tmp = 0;
    for(int i = 0; i < len; i++){
        tmp += (P[i] - '0');
        tmp %= num;
        tmp *= 10;
    }
    if(!tmp) return true;
    return false;
}

int foo(){
    int ret = 0x6f6f6f6f;
    for(int i = 2; i <= MAX; i++){
        if(chk[i]) continue;
        if(divide(i)) {
            ret = min(ret, i);
        }
    }
    return ret;
}

int main(){
    cin >> P >> K;
    chk_prime();
    int answer = foo();
    if(answer < K) cout << "BAD " << answer << '\n';
    else cout << "GOOD\n";
}
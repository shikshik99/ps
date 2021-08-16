#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string arr;
int N, K, idx = 0;

bool chk_dup(char ch, int tmp){
    for(int i = 0; i < N; i++){
        if(ch == arr[i] && tmp != i) return true;
    }

    return false;
}

int main(){
    cin >> N >> K;

    arr.resize(N, '?');

    int tmp;
    char ch;

    while(K--){
        cin >> tmp >> ch;
        idx -= tmp;
        while(idx < 0) idx += N;
        if(arr[idx] != '?' && ch != arr[idx]) cout << '!', exit(0);

        arr[idx] = ch;
    }

    for(int i = 0; i < N; i++){
        if(arr[i] == '?') continue;
        if(chk_dup(arr[i], i)) cout << '!', exit(0);
    }

    int cnt = N;
    while(cnt--){
        cout << arr[idx++];
        idx %= N;   
    }
}
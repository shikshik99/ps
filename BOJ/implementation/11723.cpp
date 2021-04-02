#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool chk[21];

void run_add(int idx){
    chk[idx] = true;
}

void run_remove(int idx){
    chk[idx] = false;
}

void run_check(int idx){
    if(chk[idx]) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void run_toggle(int idx){
    if(chk[idx]) chk[idx] = false;
    else chk[idx] = true;
}

void run_all(){
    memset(chk, true, sizeof(chk));
}

void run_empty(){
    memset(chk, false, sizeof(chk));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, ii; cin >> N;
    string cmd;
    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "all") run_all();
        else if(cmd == "empty") run_empty();
        else{
            cin >> ii;
            if(cmd == "add") run_add(ii);
            if(cmd == "remove") run_remove(ii); 
            if(cmd == "check") run_check(ii);
            if(cmd == "toggle") run_toggle(ii);
        }
    }
}
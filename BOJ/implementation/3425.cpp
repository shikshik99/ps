#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1000000000
using ll = long long;

stack <ll> s;
vector <string> cmd;
vector <ll> num;

void NUM(ll tmp){
    s.push(tmp);
}

bool POP(){
    if(s.empty()) {
        cout << "ERROR\n";
        return false;
    }

    s.pop();

    return true;
}

bool INV(){
    if(s.empty()) {
        cout << "ERROR\n";
        return false;
    }

    ll tmp = s.top(); s.pop();
    s.push(tmp * -1);

    return true;
}

bool DUP(){
    if(s.empty()) {
        cout << "ERROR\n";
        return false;
    }

    s.push(s.top());

    return true;
}

bool SWP(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();
    s.push(A), s.push(B);

    return true;
}

bool ADD(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();

    if(abs(A + B) > MAX){
        cout << "ERROR\n";
        return false;
    }

    s.push(A + B);

    return true;
}

bool SUB(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();

    if(abs(B - A) > MAX){
        cout << "ERROR\n";
        return false;
    }

    s.push(B - A);

    return true;
}

bool MUL(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();

    if(abs(A * B) > MAX){
        cout << "ERROR\n";
        return false;
    }

    s.push(A * B);

    return true;
}

bool DIV(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    bool f = true;
    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();

    if(!A){
        cout << "ERROR\n";
        return false;
    }

    if(A < 0) f ^= true;
    if(B < 0) f ^= true;

    if(f) s.push(abs(B) / abs(A));
    else s.push((abs(B) / abs(A)) * -1);

    return true;
}

bool MOD(){
    if(s.size() < 2) {
        cout << "ERROR\n";
        return false;
    }

    bool f = true;
    ll A, B;
    A = s.top(), s.pop(), B = s.top(), s.pop();

    if(!A){
        cout << "ERROR\n";
        return false;
    }

    if(B < 0) f ^= true;

    if(f) s.push(abs(B) % abs(A));
    else s.push((abs(B) % abs(A)) * -1);

    return true;
}

void CLEAR(){
    while(!s.empty()) s.pop();
    cmd.clear(), num.clear();
}

void foo(){
    int N, tmp, idx;
    cin >> N;
    for(int i = 0; i < N; i++){
        while(!s.empty()) s.pop();

        bool flag = true;
        idx = 0;
        cin >> tmp;
        s.push(tmp);
        for(int j = 0; j < cmd.size(); j++){
            if(cmd[j] == "NUM") NUM(num[idx++]);
            if(cmd[j] == "POP") flag = POP();
            if(cmd[j] == "INV") flag = INV();
            if(cmd[j] == "DUP") flag = DUP();
            if(cmd[j] == "SWP") flag = SWP();
            if(cmd[j] == "ADD") flag = ADD();
            if(cmd[j] == "SUB") flag = SUB();
            if(cmd[j] == "MUL") flag = MUL();
            if(cmd[j] == "DIV") flag = DIV();
            if(cmd[j] == "MOD") flag = MOD();

            if(!flag) break;
        }
        if(!flag) continue;
        if(s.size() != 1) cout << "ERROR\n";
        else cout << s.top() << '\n';
    }
    CLEAR();
}

int main(){
    string tmp = "";
    while(tmp != "QUIT"){
        cin >> tmp;
        if(tmp == "END") {
            foo(), cout << '\n';
            continue;
        }
        cmd.push_back(tmp);
        if(tmp == "NUM") cin >> tmp, num.push_back(stoll(tmp));
    }
}
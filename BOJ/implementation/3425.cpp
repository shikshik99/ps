#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define MAX 1000000000

stack <int> s;
vector <string> cmd;
vector <int> num;

void clear_stack(){
    while(!s.empty()) s.pop();
}

bool MOD(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}

    int a, b;
    bool f = true;
    a = s.top(), s.pop(), b = s.top(), s.pop();
    
    if(!a) {cout << "ERROR\n"; return false;}

    if(b < 0) f = false;

    b = abs(b) % abs(a);
    if(!f) b *= -1;
    s.push(b);

    return true;
    
}

bool DIV(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}
    
    int a, b;
    bool f = true;
    a = s.top(), s.pop(), b = s.top(), s.pop();
    
    if(!a) {cout << "ERROR\n"; return false;}

    if(a < 0) f ^= true;
    if(b < 0) f ^= true;

    b = abs(b) / abs(a);
    if(!f) b *= -1;
    s.push(b);

    return true;
}

bool MUL(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}
    
    long long a, b;
    a = s.top(), s.pop(), b = s.top(), s.pop();

    if(abs(a * b) > MAX) {cout << "ERROR\n"; return false;}

    s.push(a * b);
    return true;
}

bool SUB(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}
    
    int a, b;
    a = s.top(), s.pop(), b = s.top(), s.pop();
    
    if(abs(b - a) > MAX) {cout << "ERROR\n"; return false;}
    
    s.push(b - a);
    return true;
}

bool ADD(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}

    int a, b;
    a = s.top(), s.pop(), b = s.top(), s.pop();
    
    if(abs(a + b) > MAX) {cout << "ERROR\n"; return false;}

    s.push(a + b);
    return true;
}

bool SWP(){
    if(s.size() < 2) {cout << "ERROR\n"; return false;}
    
    int a, b;
    a = s.top(), s.pop(), b = s.top(), s.pop();
    s.push(a), s.push(b);
    return true;
}

bool DUP(){
    if(s.empty()) {cout << "ERROR\n"; return false;}
    s.push(s.top());
    return true;
}

bool INV(){
    if(s.empty()) {cout << "ERROR\n"; return false;}
    int tmp = s.top();
    s.pop(); s.push(tmp * -1);
    
    return true;
}

bool POP(){
    if(s.empty()) {cout << "ERROR\n"; return false;}
    s.pop();
    return true;
}

void NUM(int tmp){
    s.push(tmp);
}

void foo(int v){
    clear_stack();
    s.push(v);

    int num_idx = 0, len = cmd.size();
    for(int i = 0; i < len; i++){
        if(cmd[i] == "NUM"){
            NUM(num[num_idx]), num_idx++;
        }
        else if(cmd[i] == "POP"){
            if (!POP()) return;
        }
        else if(cmd[i] == "INV"){
            if (!INV()) return;
        }
        else if(cmd[i] == "DUP"){
            if (!DUP()) return;
        }
        else if(cmd[i] == "SWP"){
            if(!SWP()) return;
        }
        else if(cmd[i] == "ADD"){
            if(!ADD()) return;
        }
        else if(cmd[i] == "SUB"){
            if(!SUB()) return;
        }
        else if(cmd[i] == "MUL"){
            if(!MUL()) return;
        }
        else if(cmd[i] == "DIV"){
            if(!DIV()) return;
        }
        else if(cmd[i] == "MOD"){
            if(!MOD()) return;
        }
    }
    if(s.size() != 1) cout << "ERROR\n";
    else cout << s.top() << '\n', clear_stack();
}

int main(){
    string str = "";
    int N, tmp;

    while(str != "QUIT"){
        cin >> str;
        if(str == "END"){
            cin >> N;
            for(int i = 0; i < N; i++) cin >> tmp, foo(tmp);
            cmd.clear(), num.clear();
            clear_stack();
            cout << '\n';
        }
        else if(str == "NUM") cmd.push_back(str), cin >> str, num.push_back(stoi(str));
        else cmd.push_back(str);
    }
}
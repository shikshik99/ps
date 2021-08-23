#include <iostream>
using namespace std;

bool tmp[26] = {false, };
bool chk[26] = {false, };
bool alpha[26] = {false, };
int L, C;

void foo(int len, int idx, int ja, int mo){
    if(len == L && ja >= 2 && mo >= 1){
        for(int i = 0; i < 26; i++) {
            if(!chk[i]) continue;
            cout << char(i + 'a');
        }
        cout << '\n';
        return;
    }

    for(int i = idx + 1; i < 26; i++){
        if(!alpha[i]) continue;
        
        chk[i] = true;
        foo(len + 1, i, ja + !tmp[i], mo + tmp[i]);
        chk[i] = false;
    }
}

int main(){
    cin >> L >> C;
    
    tmp['a' - 'a'] = true, tmp['e' - 'a'] = true, tmp['i' - 'a'] = true, tmp['o' - 'a'] = true, tmp['u' - 'a'] = true;
    char ch;
    for(int i = 0; i < C; i++) cin >> ch, alpha[ch - 'a'] = true;
    foo(0, -1, 0, 0);
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map <int, bool>m;
vector <string> v;
int n, k, answer = 0;

void chk_string(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt++;
        for(int j = 0; j < v[i].length(); j++){
            if(!m[v[i][j] - 'a']) {cnt--; break;}
        }
    }
    answer = answer > cnt ? answer : cnt;
}

void foo(int idx, int depth){
    if(depth == k - 5){
        chk_string();
        return;
    }
    
    for(int i = idx; i < 26; i++){
        if(i == 0 || i == 2 || i== 8 || i == 13 || i == 19) continue;
        m[i] = true;
        foo(i + 1, depth + 1);
        m[i] = false;
    }
}

string wood_cutting(string str){
    string tmp;
    for(int i = 4; i < str.length() - 4; i++) tmp += str[i];
    return tmp;
}

int main(){
    for(int i = 0; i < 26; i++) m[i] = false;
    m[0] = true, m[2] = true, m[8] = true, m[13] = true, m[19] = true;
    
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i], v[i] = wood_cutting(v[i]);
    if(k < 5) {cout << 0; return 0;}
    
    foo(0, 0);

    cout << answer;
}
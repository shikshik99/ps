#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, K;
vector <string> v;
map <int, bool> m;

string foo(string str){
    string tmp = "";
    for(int i = 4; i < str.length() - 4; i++){
        if(m[str[i] - 'a']) continue;
        tmp += str[i];
    }

    return tmp;
}

int chk_cnt(){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].length(); j++){
            if(!m[v[i][j] - 'a']) {cnt--; break;}
        }
        cnt++;
    }

    return cnt;
}

int combination(int idx, int depth){
    if(depth == K){
        return chk_cnt();
    }

    int cnt = 0;
    for(int i = idx; i < 26; i++){
        if(m[i]) continue;
        m[i] = true;
        cnt = max(combination(i + 1, depth + 1), cnt);
        m[i] = false;
    }

    return cnt;
}

int main(){
    string str;
    int answer = 0;
    cin >> N >> K;
    
    for(int i = 0; i < 26; i++) m[i] = false;
    m['a' - 'a'] = true, m['n' - 'a'] = true, m['t' - 'a'] = true, m['i' - 'a'] = true, m['c' - 'a'] = true;
    
    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(foo(str));
    }

    if(K < 5) {cout << "0\n"; return 0;}

    K -= 5;

    for(int i = 0; i < 26 - (K - 1); i++){
        answer = max(answer, combination(i, 0));
    }

    cout << answer << '\n';
}
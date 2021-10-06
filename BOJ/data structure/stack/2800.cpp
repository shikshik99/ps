#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector <string> answer;
string str;
bool chk[201] = {false, };
pii arr[11];
int N = 0;

void foo(){
    stack <int> s;
    int cnt = 0;
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(str[i] == '('){
            s.push(cnt);
            arr[cnt++].first = i;
            N++;
        }
        else if(str[i] == ')'){
            int tmp = s.top();
            s.pop();
            arr[tmp].second = i;
        }
    }
}

void add_str(){
    string ret = "";
    int len = str.length();
    for(int i = 0; i < len; i++){
        if(str[i] == '(' || str[i] == ')'){
            if(!chk[i]) continue;
        }
        ret += str[i];
    }

    answer.push_back(ret);
}

void solve(int depth){
    add_str();
    if(depth == N) return;
    int fi = arr[depth].first;
    int se = arr[depth].second;
    chk[fi] = true;
    chk[se] = true;
    solve(depth + 1);
    chk[fi] = false;
    chk[se] = false;
    solve(depth + 1);
}

int main(){
    cin >> str;
    foo();
    solve(0);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    for(auto it : answer) {
        if(it == str) continue;
        cout << it << '\n';
    }
}
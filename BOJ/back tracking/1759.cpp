#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <char> v;
int L, C;

bool ok(string str){
    int a = 0, b = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') a++;
        else b++;
    }
    if(a >= 1 && b >= 2) return true;
    return false;
}

void foo(int depth, int idx, string str){
    if(depth == L && ok(str)) {
        cout << str << '\n';
        return;
    }
    for(int i = idx; i < C; i++){
        str += v[i];
        foo(depth + 1, i + 1, str);
        str.pop_back();
    }
}

int main(){
    char ch;
    cin >> L >> C;
    for(int i = 0; i < C; i++) cin >> ch, v.push_back(ch);
    sort(v.begin(), v.end());
    foo(0, 0, "");
}
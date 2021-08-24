#include <iostream>
#include <string>
using namespace std;

char arr[3] = {'1', '2', '3'};
string ans;
int N;

bool possible(){
    int len = ans.length();
    for(int i = 1; i <= len / 2; i++){
        for(int j = 0; j < len; j++){
            if(j + (2 * i) > len) break;
            string A = ans.substr(j, i);
            string B = ans.substr(j + i, i);
            if(A == B) return false;
        }
    }
    return true;
}

void foo(int depth){
    if(depth == N) cout << ans, exit(0);
    
    for(int i = 0; i < 3; i++){
        ans += arr[i];
        if(possible()) foo(depth + 1);
        ans.pop_back();
    }
}

int main(){
    ans = "1";
    cin >> N;
    foo(1);
}
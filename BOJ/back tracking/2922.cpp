#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ja = 20, mo = 5;
string str;
int len;

ll solve(int idx, int cnt_ja, int cnt_mo, int L){
    if(cnt_ja >= 3 || cnt_mo >= 3) return 0;
    if(idx == len){
        if(!L) return 0;
        return 1;
    }

    ll ret = 0;
    if(str[idx] == '_'){
        ret += (solve(idx + 1, 0, cnt_mo + 1, L) * mo);
        ret += (solve(idx + 1, cnt_ja + 1, 0, L) * ja);
        ret += (solve(idx + 1, cnt_ja + 1, 0, L + 1));
    }
    else{
        if(str[idx] == 'A' || str[idx] == 'E' || str[idx] == 'I' || str[idx] == 'O' || str[idx] == 'U')
            ret = solve(idx + 1, 0, cnt_mo + 1, L);
        else{
            if(str[idx] == 'L') L++;
            ret = solve(idx + 1, cnt_ja + 1, 0, L);
        }
    }

    return ret;
}

int main(){
    cin >> str;
    len = str.length();

    cout << solve(0, 0, 0, 0) << '\n';
}
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

string arr[MAX];
int N;

bool possible(int x, int y){
    int chk1[26], chk2[26];
    memset(chk1, -1, sizeof(chk1));
    memset(chk2, -1, sizeof(chk2));

    string A = arr[x], B = arr[y];
    if(A.length() != B.length()) return false;

    int len = A.length();
    
    for(int i = 0; i < len; i++){
        int aidx = A[i] - 'a', bidx = B[i] - 'a';
        if(chk1[aidx] == -1 && chk2[bidx] == -1) chk1[aidx] = bidx, chk2[bidx] = aidx;
        else if(chk1[aidx] != bidx) return false;
    }

    return true;
}

int solve(){
    int ret = 0;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(possible(i, j)) ret++;
        }
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    cout << solve() << '\n';
}
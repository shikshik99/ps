#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <string>v;

bool cmp(string A, string B){
    if(A.length() < B.length()) return true;
    else if(A.length() == B.length()){
        int acnt = 0, bcnt = 0;
        for(int i = 0; i < A.length(); i++){
            if(A[i] >= '0' && A[i] <= '9') acnt = acnt + (A[i] - '0');
            if(B[i] >= '0' && B[i] <= '9') bcnt = bcnt + (B[i] - '0');
        }
        if(acnt < bcnt) return true;
        else if(acnt == bcnt){
            return A < B ? true : false;
        }
        else return false;
    }
    else return false;
}

int main(){
    int N;
    cin >> N, v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for(auto it : v) cout << it << '\n';
}
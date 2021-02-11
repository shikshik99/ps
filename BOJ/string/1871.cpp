#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

vector <string>v;
vector <string>ans;

int main(){
    string A, B;
    ll N, j = 0, tmp1, tmp2;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        j = 0;
        A = "", B = "";
        while(v[i][j] != '-') A += v[i][j++];
        j++; 
        while(j < v[i].length()) B += v[i][j++];
        j = tmp1 = tmp2 = 0;
        while(j < A.size()) tmp1 = tmp1 + (A[j] - 'A') * pow(26, (A.size() - j - 1)), j++;
        j = 0;
        while(j < B.size()) tmp2 = tmp2 * 10 + (B[j++] - '0');
        if(abs(tmp1 - tmp2) <= 100) ans.push_back("nice");
        else ans.push_back("not nice");
    }
    for(auto it : ans) cout << it << '\n';
}
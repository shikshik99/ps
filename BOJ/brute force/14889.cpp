#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[21][21];
int N;
bool chk[21];
vector <vector<int>>v;
vector <int>combi;
vector <int>v1,v2;

void combination(int depth, int next){
    if(depth == N/2) {v.push_back(combi); return;}
    for(int i = next; i <= N; i++){
        if(chk[i]) continue;
        combi[depth] = i;
        chk[i] = true;
        combination(depth+1, i+1);
        chk[i] = false;
    }
}

int calc(){
    int a = 0, b = 0;
    for(int i = 0; i < N/2; i++){
        for(int j = i; j < N/2; j++){
            a += arr[v1[i]][v1[j]];
            a += arr[v1[j]][v1[i]];
        }
    }
    for(int i = 0; i < N/2; i++){
        for(int j = i; j < N/2; j++){
            b += arr[v2[i]][v2[j]];
            b += arr[v2[j]][v2[i]];
        }
    }
    return max(a,b) - min(a,b);
}

int foo(){
    int ans = 0x7f7f7f7f;
    
    v1.resize(N/2); v2.resize(N/2);
    for(int i = 0; i < v.size()/2; i++){
        for(int j = 0; j < N/2; j++) v1[j] = v[i][j];
        for(int j = 0; j < N/2; j++) v2[j] = v[v.size()- i - 1][j];
        ans = min(calc(), ans);
    }

    return ans;
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    combi.resize(N/2);
    combination(0, 1);
    cout << foo();
}
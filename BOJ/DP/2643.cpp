#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pii pair<int,int>

vector <pii>v;
int arr[101];
int N;

int foo(int idx){
    if(arr[idx] != -1) return arr[idx];
    arr[idx] = 0;
    for(int i = idx+1; i <= N; i++) if(v[idx].second >= v[i].second) arr[idx] = max(arr[idx], foo(i));
    return arr[idx] += 1;
}

bool cmp(pii a, pii b){
    if(a.first > b.first) return true;
    else if(a.first == b.first) return a.second > b.second ? true : false;
    else return false;
}

int main(){
    memset(arr, -1, sizeof(arr));
    int a,b;
    cin >> N;
    v.resize(N+1);
    v[0].first = v[0].second = 0x7f7f7f7f;
    for(int i = 1; i < N+1; i++){
        cin >> a >> b;
        if(b > a) swap(a,b);
        v[i] = {a,b};
    }
    sort(v.begin(), v.end(), cmp);
    cout << foo(0) - 1;
}
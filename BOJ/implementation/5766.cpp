#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second ? true : false;
    return a.first > b.first ? true : false;
}

int arr[10001];
vector <pii> v;
int N, M;

int main(){
    while((cin >> N >> M) && (N || M)){
        memset(arr, 0, sizeof(arr));
        v.clear();
        int num;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) cin >> num, arr[num]++;
        }
        for(int i = 0; i < 10001; i++){
            if(arr[i]) v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end(), cmp);
        num = v[1].first;
        for(pii it : v){
            if(num == it.first) cout << it.second << ' ';
        }
        cout << '\n';
    }
}
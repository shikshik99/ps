#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
using pii = pair <int, int>;

pii arr[MAX];
int N;

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second > b.second ? true : false;
    return a.first < b.first ? true : false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int start_month, start_day, end_month, end_day;
    for(int i = 0; i < N; i++){
        cin >> start_month >> start_day >> end_month >> end_day;
        arr[i].first = start_month * 100 + start_day;
        arr[i].second = end_month * 100 + end_day;
    }

    sort(arr, arr + N);
    int start = 301, eend = 1130;
    int answer = 0;
    int date = start, curr_idx = 0, idx = 0, tmp = 0;

    if(arr[0].first > start) cout << 0 << '\n', exit(0);
    
    while(date <= eend && idx < N){
        while(arr[idx].first <= date && idx < N){
            if(arr[idx].second > tmp) curr_idx = idx, tmp = arr[idx].second;
            idx++;
        }
        date = tmp;
        answer++;
    }

    if(date > eend) cout << answer << '\n';
    else cout << 0 << '\n';
}
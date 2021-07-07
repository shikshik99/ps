#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    int recom = 0;
    int duration = 0;
};

vector <student> v;
int arr[21] = {0,};
int N, K;

bool chk_exist(int tmp){
    for(int i = 0; i < N; i++){
        if(arr[i] == tmp) {
            v[tmp].recom++; 
            return true;
        }
    }

    return false;
}

void find_place(int new_idx){
    if(chk_exist(new_idx)) return;
    
    v[new_idx].recom = 1;

    int cnt = 10000, du = 0, tmp, idx, ii;
    for(int i = 0; i < N; i++){
        if(!arr[i]) {
            arr[i] = new_idx;
            return;
        }
        tmp = arr[i];
        if(v[tmp].recom < cnt) cnt = v[tmp].recom, du = v[tmp].duration, idx = tmp, ii = i;
        else if(v[tmp].recom == cnt && v[tmp].duration > du) cnt = v[tmp].recom, du = v[tmp].duration, idx = tmp, ii = i;
    }
    v[idx].duration = 0, v[idx].recom = 0;
    arr[ii] = new_idx;
}

int main(){
    v.resize(101);

    int tmp;
    cin >> N >> K;
    
    for(int i = 0; i < K; i++){
        cin >> tmp;
        find_place(tmp);
        for(int i = 0; i < N; i++) {
            v[arr[i]].duration++;
        }
    }
    
    vector <int> answer;
    for(int i = 0; i < N; i++){
        answer.push_back(arr[i]);
    }
    sort(answer.begin(), answer.end());
    for(auto it : answer) cout << it << ' ';
}
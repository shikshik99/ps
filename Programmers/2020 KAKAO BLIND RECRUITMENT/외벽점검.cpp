#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool chk[8] = {false, };
bool chk_weak[15] = {false, };
int N, cnt = 1, len, sizz;
vector <int> v;

bool chk_dist(vector<int> weak, vector<int> dist){
    memset(chk_weak, false, sizeof(chk_weak));
        
    int tmp, pivot = 0;
    for(int i = 0; i < len; i++){
        if(chk[i]){
            tmp = dist[i] + weak[pivot];
            while(weak[pivot] <= tmp && pivot < sizz){
                chk_weak[pivot++] = true;
            }
        }
    }
    
    for(int i = 0; i < sizz; i++){
        if(!chk_weak[i]) return false;
    }
    
    return true;
}

bool choose_friend(vector<int> dist){
    vector<int> tmp;
    do{
        tmp = v;
        for(int i = 0; i < 4; i++){
            if(chk_dist(tmp, dist)) return true;
            tmp[0] += N, sort(tmp.begin(), tmp.end());
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n, len = dist.size(), sizz = weak.size(), v = weak;
    sort(dist.begin(), dist.end());
    
    while(cnt <= len){
        for(int i = 0; i < cnt; i++) chk[i] = true;
        if(choose_friend(dist)) return cnt;
        cnt++;
    }
    
    return -1;
}
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
#define pii pair<int, int>

struct compare{
    bool operator()(pii a, pii b){
        return a.first > b.first;
    }
};

priority_queue <pii, vector<pii>, compare> pq;
bool chk[200001];

int solution(vector<int> times, long long k) {
    memset(chk, false, sizeof(chk));
    long long cnt = 0;
    int siz = times.size();
    for(int i = 0; i < times.size(); i++) pq.push({times[i], i});
    
    while(!pq.empty()) {
        pii tmp = pq.top();
        tmp.first -= cnt;
        cnt += tmp.first;
        if(k < pq.size() * tmp.first){
            k %= pq.size();
            cnt = 0;
            for(int i = 0; i < siz; i++){
                if(chk[i]) continue;
                if(cnt == k) return i + 1;
                cnt++;
            }
        }
        else{
            k -= (pq.size() * tmp.first);
            chk[tmp.second] = true;
        }
        pq.pop();
    }
    return -1;
}
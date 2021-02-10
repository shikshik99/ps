#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

priority_queue <int, vector<int>, greater<int>>pq;
int cnt[8001] = {0};

int main(){
    bool flag = false;
    int N, a, ma = 0, mi = 0, ans = 0, piv = 0;
    double sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(i == 0) ma = mi = a;
        sum += a;
        pq.push(a);
        ma = max(ma, a);
        mi = min(mi, a);
        if(a<0) cnt[4000 - abs(a)]++;
        else cnt[4000+a]++;
    }
    for(int i = 0; i < N/2; i++) pq.pop();
    for(int i = 0; i < 8001; i++){
        if(cnt[i] > piv) {piv = cnt[i]; ans = i;}
    }
    for(int i = 0; i < 8001; i++){
        if(piv == cnt[i] && !flag) {flag = true;} 
        else if(piv == cnt[i] && flag) {ans = i; break;}
    }
    ans -= 4000;
    cout << floor((sum/N)+0.5) << '\n' << pq.top()  << '\n' << ans << '\n' << ma-mi;
}

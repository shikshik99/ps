#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

vector <pair<ll,ll>>v;
vector <ll>v1;

ll foo(ll sum, ll N){
    ll low = 0, high = N-1, mid;
    bool flag = false;
    while(low <= high){
        mid = (low+high)/2;
        if(v1[mid] - v[mid].second> sum) high = mid - 1;
        else if(v1[mid] - v[mid].second < sum) low = mid + 1;
        else if(v1[mid] - v[mid].second == sum) {flag = true; break;}
    }
    if(flag) return v1[mid - 1] == v1[mid] ? mid-1 : mid;
    ll a, b;
    a = abs(sum-v1[low]);
    b = abs(sum-v1[high]);
    if(a == b) return high;
    return a < b ? low : high;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, a, b, sum = 0, ans;
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < N; i++){
        sum += v[i].second;
        v1.push_back(sum);
    }
    ans = foo(sum/2, N);
    if(N==2){
        ans = v[1].second > v[0].second ? 1 : 0;
    }
    cout << v[ans].first;
}
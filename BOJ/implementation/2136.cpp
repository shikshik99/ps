#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <pii> v;

int main(){
    int N, L, tmp, cnt = 0, l = 0, r = 0;
    cin >> N >> L;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        if(tmp < 0){
            cnt++;
            l = -tmp > l ? -tmp : l;   
            v.push_back({-tmp, i + 1});
        }
        else {
            v.push_back({tmp, i + 1});
            r = r > L - tmp ? r : L - tmp;
        }
    }
    sort(v.begin(), v.end());

    if(l > r) cout << v[cnt - 1].second << ' ' << l;
    else cout << v[cnt].second << ' ' << r;
}
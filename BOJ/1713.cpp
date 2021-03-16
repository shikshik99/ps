#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

vector <pii> v;
int rc[101];
vector <int> answer;

int main(){
    int n, m, tmp;
    pii mi;
    bool flag;
    cin >> n >> m;
    v.resize(n, {-1, 0});
    rc[0] = 0x7f7f7f7f;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) v[j].second++;
        flag = false;
        cin >> tmp;
        mi.first = 0;
        mi.second = 0x7f7f7f7f;
        for(int j = 0; j < n; j++){
            if(v[j].first == tmp) {rc[tmp]++, flag = true; break;}
            else if(v[j].first == -1) {rc[tmp]++, v[j].first = tmp, v[j].second = 0, flag = true; break;}
            else{
                if(rc[mi.first] > rc[v[j].first]) mi.first = v[j].first, mi.second = v[j].second;
                else if(rc[mi.first] == rc[v[j].first]) {if(mi.second <= v[j].second) mi.first = v[j].first, mi.second = v[j].second;}
            }
        }
        if(flag) continue;
        for(int j = 0; j < n; j++){
            if(v[j].first == mi.first) {rc[mi.first] = 0, v[j].first = tmp, rc[tmp]++, v[j].second = 0; break;}
        }
    }
    for(auto it : v) answer.push_back(it.first);
    sort(answer.begin(), answer.end());
    for(auto it : answer) cout << it << ' ';
}
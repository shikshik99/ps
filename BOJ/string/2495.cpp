#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <string>v;
vector <int>ans;

int main(){
    v.resize(3);
    int ma = 0, tmp;
    for(int i = 0; i < 3; i++) cin >> v[i];
    for(int i = 0; i < 3; i++){
        ma = tmp = 1;
        for(int j = 1; j < v[i].length(); j++){
            if(v[i][j] == v[i][j-1]) tmp++;
            else ma = max(ma, tmp), tmp = 1;
        }
        ma = max(ma, tmp), ans.push_back(ma);
    }
    for(auto it : ans) cout << it << '\n';
}
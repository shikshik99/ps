#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector <int> v;
int G;

int main(){
    cin >> G;
    
    ll s = 1, e = 1, tmp = 0;
    while(1){
        if(tmp >= G) s++;
        else e++;
        tmp = (e * e) - (s * s);
        if(tmp == G) v.push_back(e);

        if(e - s <= 1 && tmp > G) break;
    }

    if(v.empty()) v.push_back(-1);
    for(int it : v) cout << it << '\n';
}
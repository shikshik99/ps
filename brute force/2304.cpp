#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <int,int>m;
map <int,int>::iterator iter, iter2;
int N, ma = 0;

int foo(){
    iter = m.begin();
    int width = iter->first, height = iter->second, ans = 0, tmp = 0;
    for(iter; iter != m.end(); iter++){
        if(iter->second == ma){ans += (iter->first-width)*height; break;}
        if(iter->second <= height) continue;
        else if(iter->second > height){
            ans += (iter->first-width)*height;
            height = iter->second;
            width = iter->first;
        }
    }
    iter2 = m.end(); iter2--;
    width = iter2->first;
    height = iter2->second;
    for(iter2; iter2 != m.begin(); iter2--){
        if(iter2->second == ma || iter2 == iter){ans += (width - iter2->first)*height; break;}
        if(iter2->second <= height) continue;
        else if(iter2->second > height){
            ans += (width - iter2->first)*height;
            height = iter2->second;
            width = iter2->first;
        }
    }
    if(iter == iter2) ans += ma;
    else ans += (iter2->first-iter->first+1) * ma;
    return ans;
}

int main(){
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b; ma = max(b, ma);
        m.insert(make_pair(a,b));
    }
    cout << foo();
}
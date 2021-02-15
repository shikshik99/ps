#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int calc(int a, int b, int c, int d){
    return min(a*1000+b*100+c*10+d, min(b*1000+c*100+d*10+a, min(c*1000+d*100+a*10+b, d*1000+a*100+b*10+c)));
}

int main(){
    int tmp = 0;
    v.resize(4);
    for(int i = 0; i < 4; i++) cin >> v[i];
    tmp = calc(v[0],v[1],v[2],v[3]);
    v.clear();
    for(int a = 1; a < 10; a++){
        for(int b = 1; b < 10; b++){
            for(int c = 1; c < 10; c++){
                for(int d = 1; d < 10; d++) v.push_back(calc(a,b,c,d));
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int i = 1;
    for(auto it : v){
        if(tmp == it) {cout << i; return 0;}
        i++;
    } 
}
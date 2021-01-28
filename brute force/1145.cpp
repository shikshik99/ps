#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;
vector <int>a;
int N = 5;

int foo(){
    int tmp = v[0];
    while(1){
        int cnt = 0;
        for(int i = 0; i < N; i++) if(!(tmp%v[i])) cnt++;
        if(cnt >= 3) return tmp;
        tmp++;
    }
}

int main(){
    v.resize(5);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << foo();
}
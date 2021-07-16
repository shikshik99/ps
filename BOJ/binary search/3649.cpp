#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define NUM 10000000

vector <long long> v;

int main(){
    long long N, num;
    bool f;
    while(cin >> num){
        f = false;
        v.clear();
        
        cin >> N;
        num *= NUM;
        
        v.resize(N);
        
        for(int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());

        long long tmp, lo, hi;
        for(int i = 0; i < N - 1; i++){
            tmp = num - v[i];
            lo = lower_bound(v.begin() + i + 1, v.end(), tmp) - v.begin();
            if(v[lo] == num - v[i]){
                cout << "yes " << v[i] << ' ' << v[lo] << '\n';
                f = true;
                break;
            }
        }
        if(!f) cout << "danger\n";
    }
}
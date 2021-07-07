#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v, a;

int foo(int num){
    int l = 0, r = v.size() - 1, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(v[mid] < num) l = mid + 1;
        else if(v[mid] == num) return 1;
        else r = mid - 1;
    }

    return 0;
}

int main(){
    int N, M, tmp;
    cin >> N;
    while(N--) cin >> tmp, v.push_back(tmp);

    sort(v.begin(), v.end());
    
    cin >> M;
    while(M--) cin >> tmp, a.push_back(tmp);

    for(int i = 0; i < a.size(); i++){
        cout << foo(a[i]) << '\n';
    }
}
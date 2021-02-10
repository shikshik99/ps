#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string>v1, v2, v3;

int main(){
    int N, M, cnt = 0;
    cin >> N >> M;
    v1.resize(N);
    v2.resize(M);
    for(int i = 0; i < N; i++) cin >> v1[i];
    for(int i = 0; i < M; i++) cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < N; i++){
        int l = 0, r = v2.size() - 1, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(v2[mid].compare(v1[i]) < 0) l = mid + 1;
            else if (v2[mid].compare(v1[i]) == 0) {cnt++; v3.push_back(v1[i]); break;}
            else r = mid - 1;
        }
    }
    cout << cnt;
    for(int i = 0; i < v3.size(); i++) cout << '\n' << v3[i];
}
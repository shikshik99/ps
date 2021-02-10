#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, left, right, mid, tmp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> tmp;
        left = 0;
        right = N - 1;
        while(left <= right){
            mid = (left+right)/2;
            if(v[mid] > tmp) right = mid - 1;
            else if(v[mid] == tmp) break;
            else left = mid + 1;
        }
        if(v[mid] == tmp) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
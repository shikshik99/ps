#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
vector <int>answer;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int cnt, i = 0, M = N;
    while(M--){
        cnt = arr[i], arr[i] = 0, answer.push_back(i+1);
        if(!M) break;
        if(cnt > 0){
            while(cnt--){
                i++, i %= N;
                while(!arr[i]) i++, i %= N;
            }
        }
        else {
            while(cnt++){
                i--;
                if(i < 0) i += N;
                while(!arr[i]) {
                    i--; if(i < 0) i += N;
                }
            }
        }
    }
    for(auto it : answer) cout << it << ' ';
}
#include <iostream>
#include <algorithm>
using namespace std;

int arr[3][2], ma = 0;
int fee[4];

int main(){
    int time = 1, answer = 0, cnt = 0;
    cin >> fee[1] >> fee[2] >> fee[3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++) cin >> arr[i][j], ma = max(arr[i][j], ma);
    }
    while(time <= ma){
        cnt = 0;
        for(int i = 0; i < 3; i++){
            if(arr[i][0] <= time && arr[i][1] > time) cnt++;
        }
        answer = answer + (fee[cnt] * cnt), time++;
    }
    cout << answer<<'\n';
}
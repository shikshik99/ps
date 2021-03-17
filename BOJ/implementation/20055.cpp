#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, bool>

vector <pii> belt;
vector <int> v;

int main(){
    int N, K, cnt = 0, answer = 0, num = 0, a = 0, tmp;
    cin >> N >> K;
    belt.resize(2*N, {0, false});
    v.resize(N, 0);
    for(int i = 0; i < 2 * N ; i++) cin >> belt[i].first;

    while(cnt < K){
        answer++;
        a = 0;
        num--;
        if(num < 0) num += 2 * N;
        tmp = num;
        while(a < N) {
            v[a] = tmp; a++; tmp++; tmp %= (2 * N);
        }
        tmp = (v[N - 1] + 1) % (2 * N);
        if(belt[tmp].second) belt[tmp].second = false;
        for(int j = N - 1 ; j >= 0; j--){
            if(belt[v[N - 1]].second) belt[v[N - 1]].second = false;
            if(belt[v[j]].second){
                if(j == N - 1) belt[v[j]].second = false;
                else{
                    if(belt[v[j + 1]].first && !belt[v[j + 1]].second) {
                        belt[v[j + 1]].first -= 1, belt[v[j]].second = false, belt[v[j + 1]].second = true;
                    }
                }
            }
        }
        if(!belt[v[0]].second && belt[v[0]].first) belt[v[0]].second = true, belt[v[0]].first -= 1;
        cnt = 0;
        for(int j = 0; j < 2 * N; j++) if(belt[j].first == 0) cnt++;
    }
    cout << answer;
}
#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 100001
using namespace std;
using ll = long long;

stack <int> s;
int H[MAX];
int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> H[i];

    H[N] = 0; // 마지막에 남은 친구들 확인하기 위한 트릭
    ll answer = 0;
    for(int i = 0; i <= N; i++){
        ll height, width;
        while(!s.empty() && H[s.top()] >= H[i]){
            height = H[s.top()];
            s.pop();
            // s.pop()을 해서 내 왼쪽에서 나보다 작은애를 찾음(왼쪽 - 오른쪽 보면서 나보다 작은 애들만 내 밑에 들어가있어서 보장된다.)
            width = (s.empty() ? i : i - s.top() - 1); // empty라면 현재까지 내가 제일 낮았으므로 내 높이로 커버할 수 있는 너비는 현재까지 본 너비.
            answer = max(answer, height * width);
        }

        s.push(i);
    }

    cout << answer << '\n';
}
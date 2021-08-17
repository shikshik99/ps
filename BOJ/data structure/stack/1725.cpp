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
    ll width, height, answer = 0;
    for(int i = 0; i < N; i++) cin >> H[i];

    H[N] = 0;
    for(int i = 0; i <= N; i++){
        while(!s.empty() && H[s.top()] >= H[i]){
            height = H[s.top()];
            s.pop();
            if(s.empty()) width = i;
            else width = i - s.top() - 1; // 단순히 i - s.top()을 하면 내 이전에 있던 높은 애들 까지 셀 수가 없다.(pop 하고 남은 top이 내 전에 있던 큰 놈들 까지 센 것)
            answer = max(answer, width * height);
        }
        s.push(i);
    }

    cout << answer << '\n';
}
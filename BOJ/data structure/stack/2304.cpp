#include <iostream>
#include <stack>
#define MAX 1001
using namespace std;

stack <int> l, r;
int height[MAX] = {0, };
int N;

int main(){
    cin >> N;

    int tmp;
    for(int i = 0; i < N; i++) cin >> tmp, cin >> height[tmp - 1];

    int answer = 0;
    for(int i = 0; i < MAX; i++){
        if(l.empty()) {
            l.push(i);
            continue;
        }

        if(height[l.top()] < height[i]) answer += ((i - l.top()) * height[l.top()]), l.push(i);
    }
    
        for(int i = MAX - 1; i > -1; i--){
        if(r.empty()) {
            r.push(i);
            continue;
        }

        if(height[r.top()] < height[i]) answer += ((r.top() - i) * height[r.top()]), r.push(i);
    }

    answer += (r.top() - l.top() + 1) * height[l.top()];

    cout << answer << '\n';
}
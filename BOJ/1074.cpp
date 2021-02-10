#include <iostream>
using namespace std;

int N, r, c, cnt = 0;

void foo(int n, int a, int b){
    if(n == 1){
        if(a==r&&b==c){cout << cnt; return;}cnt++;
        if(a==r&&b+1==c){cout << cnt; return;}cnt++;
        if(a+1==r&&b==c){cout << cnt; return;}cnt++;
        if(a+1==r&&b+1==c){cout << cnt; return;}cnt++;
        return;
    }
    int tmp = n - 1;
    if(a <= r && r < a + (1<<tmp)&& b <= c && c < b + (1<<tmp)) foo(tmp, a, b);
    if(a <= r && r < a + (1<<tmp)&&  c >= b + (1<<tmp)){cnt = cnt + (1<<tmp*2);foo(tmp, a, b + (1<<tmp));}
    if(r >= a + (1<<tmp)&& b <= c && c < b + (1<<tmp)){cnt = cnt + (1<<tmp*2)*2;foo(tmp, a + (1<<tmp), b);}
    if(r >= a + (1<<tmp)&& c >= b + (1<<tmp)){cnt = cnt + (1<<tmp*2)*3;foo(tmp, a + (1<<tmp), b + (1<<tmp));}    
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> r >> c;
    foo(N, 0, 0);
}
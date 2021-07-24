#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7f7f7f7f
using namespace std;

vector <int> A, B;
int N, H;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> H;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(i % 2 == 0) A.push_back(tmp);
        else B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int answer = MAX, cnt = 0;
    int tmp, lo, hi;
    for(int i = 1; i <= H; i++){
        tmp = 0;
        lo = lower_bound(A.begin(), A.end(), i) - A.begin();
        tmp += A.size() - lo;

        lo = lower_bound(B.begin(), B.end(), H - i + 1) - B.begin();
        tmp += B.size() - lo;

        if(tmp < answer) answer = tmp, cnt = 1;
        else if(tmp == answer) cnt++;
    }

    cout << answer << ' ' << cnt << '\n';
}
#include <iostream>
#include <algorithm>
using namespace std;

int D[6] = {0, };

int main(){
    int N;
    int tmp1, tmp2, tmp3;
    int max1 = 0, max2 = 0, max3 = 0;
    int min1 = 0, min2 = 0, min3 = 0;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        max1 = max(D[0], D[1]) + tmp1;
        max2 = max({D[0], D[1], D[2]}) + tmp2;
        max3 = max(D[1], D[2]) + tmp3;
        min1 = min(D[3], D[4]) + tmp1;
        min2 = min({D[3], D[4], D[5]}) + tmp2;
        min3 = min(D[4], D[5]) + tmp3;
        D[0] = max1, D[1] = max2, D[2] = max3;
        D[3] = min1, D[4] = min2, D[5] = min3;
    }

    cout << max({D[0], D[1], D[2]}) << ' ' << min({D[3], D[4], D[5]}) << '\n';
}
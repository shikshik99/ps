#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll D[6] = {0,};
int A, B, C;
ll max0, max1, max2, min0, min1, min2;

int main(){
    int N;
    cin >> N;
    while(N--){
        cin >> A >> B >> C;
        max0 = max(D[0], D[1]) + A;
        max1 = max({D[0], D[1], D[2]}) + B;
        max2 = max(D[1], D[2]) + C;
        min0 = min(D[3], D[4]) + A;
        min1 = min({D[3], D[4], D[5]}) + B;
        min2 = min(D[4], D[5]) + C;
        D[0] = max0, D[1] = max1, D[2] = max2, 
        D[3] = min0, D[4] = min1, D[5] = min2;
    }

    cout << max({D[0], D[1], D[2]}) << ' ' << min({D[3], D[4], D[5]}) << '\n';
}
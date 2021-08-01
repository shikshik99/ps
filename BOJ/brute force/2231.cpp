#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int sum = i, tmp = i;
        while(tmp) sum += (tmp % 10), tmp /= 10;
        if(sum == N) cout << i << '\n', exit(0);
    }

    cout << 0 << '\n';
}
#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(M == 1 || M == 2) cout << "NEWBIE!";
    else if(M > 2 && M <= N) cout << "OLDBIE!";
    else cout << "TLE!";
}
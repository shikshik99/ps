#include <iostream>
#include <set>
using namespace std;

set <int> A;
int N, M;

int main(){
    cin >> N >> M;
    int sizz = 0, tmp;
    for(int i = 0; i < N; i++) cin >> tmp, A.insert(tmp);
    
    for(int i = 0; i < M; i++){
        cin >> tmp;
        if(A.find(tmp) != A.end()) sizz++;
    }

    cout << (N - sizz) + (M - sizz) << '\n';
}
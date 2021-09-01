#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#define MAX 200001
using namespace std;

int P[MAX];
map <string, int> m;

int find(int a){
    if(P[a] < 0) return a;
    return P[a] = find(P[a]);
}

int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return abs(P[a]);

    P[a] += P[b];
    P[b] = a;
    return abs(P[a]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, N;

    cin >> T;
    while(T--){
        memset(P, -1, sizeof(P));
        int cnt = 1;
        cin >> N;
        string A, B;
        while(N--){
            cin >> A >> B;
            if(m.find(A) == m.end()) m[A] = cnt++;
            if(m.find(B) == m.end()) m[B] = cnt++;
            int a = m[A], b = m[B];
            cout << merge(a, b) << '\n';
        }
    }
}
#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int D[MAX];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        D[i] = arr[i] + D[i - 1];
    }

    int a, b;
    while(M--){
        cin >> a >> b;
        cout << D[b] - D[a - 1] << '\n';
    }

}
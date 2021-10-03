#include <bits/stdc++.h>
#define MAX 101
using namespace std;

bool arr[MAX];
int N, M;

void boy(int num){
    for(int i = num; i <= N; i += num){
        arr[i] ^= true;
    }
}

void girl(int num){
    int l = num - 1, r = num + 1;
    while(l > 0 && r <= N && arr[l] == arr[r]) l--, r++;
    l++, r--;
    for(int i = l; i <= r; i++) arr[i] ^= true;
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    cin >> M;
    
    int tmp, num;
    while(M--){
        cin >> tmp >> num;
        if(tmp == 1) boy(num);
        else girl(num);
    }

    for(int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
        if(i % 20 == 0 || i == N) cout << '\n';
    }
}

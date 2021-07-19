#include <iostream>
#include <algorithm>
using namespace std;

char arr[16];
bool chk[16];
int L, C;

bool OK(){
    int tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < C; i++){
        if(chk[i]){
            if(arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u') tmp1++;
            else tmp2++;
        }
    }
    
    if(tmp1 >= 1 && tmp2 >= 2) return true;
    return false;
}

void combination(int idx, int depth){
    if(depth == L && OK()){
        for(int i = 0; i < C; i++){
            if(chk[i]) cout << arr[i];
        }
        cout << '\n'; return;
    }

    for(int i = idx; i < C; i++){
        if(chk[i]) continue;
        chk[i] = true;
        combination(i + 1, depth + 1);
        chk[i] = false;
    }
}

int main(){
    cin >> L >> C;
    for(int i = 0; i < C; i++) cin >> arr[i];
    sort(arr, arr + C);
    combination(0, 0);
}
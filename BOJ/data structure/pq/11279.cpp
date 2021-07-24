#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX] = {0, };
int top = 0;

bool OK(int a, int b){
    return a > b ? true : false;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void PUSH(int num) {
    arr[++top] = num;
    int tmp = top;
    while(tmp > 1){
        int par = tmp / 2;
        if(!OK(arr[par], arr[tmp])) swap(arr[par], arr[tmp]), tmp /= 2;
        else break;
    }
}

int POP() {
    if(!top) return 0;
    int ret = arr[1];
    if(top == 1){
        arr[top--] = 0;
        return ret;
    }
    
    swap(arr[1], arr[top]);
    arr[top--] = 0;
    
    int tmp = 1;
    int minidx;
    while(tmp * 2 <= top){
        int l = tmp * 2, r = tmp * 2 + 1;
        if(r <= top) minidx = arr[l] > arr[r] ? l : r;
        else minidx = l;

        if(!OK(arr[tmp], arr[minidx])) swap(arr[tmp], arr[minidx]), tmp = minidx;
        else break;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;

    int x;
    while(N--){
        cin >> x;
        if(!x) cout << POP() << '\n';
        else PUSH(x);        
    }
}
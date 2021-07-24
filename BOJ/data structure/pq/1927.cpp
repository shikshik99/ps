#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int top = 0;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

bool OK(int a, int b){
    return a > b ? true : false;
}

void PUSH(int num){
    arr[++top] = num;
    int tmp = top;
    while(OK(arr[tmp / 2], arr[tmp]) && tmp > 1){
        swap(arr[tmp], arr[tmp / 2]);
        tmp /= 2;
    }
}

int POP(){
    if(!top) return 0;
    if(top == 1) {
        top--;
        return arr[1];
    }
    int ret = arr[1];

    swap(arr[1], arr[top]);
    arr[top--] = 0x7f7f7f7f;
    int tmp = 1;
    bool f1 = true, f2 = true;
    while(tmp * 2 <= top && (f1 || f2)){
        f1 = false, f2 = false;
        if(tmp * 2 + 1 <= top) f1 = OK(arr[tmp], arr[tmp * 2 + 1]);
        if(tmp * 2 <= top) f2 = OK(arr[tmp], arr[tmp * 2]);
        if(f1 && f2){
            if(arr[tmp * 2 + 1] == arr[tmp * 2]) f1 = false;
            else {
                f1 = arr[tmp * 2 + 1] < arr[tmp * 2] ? true : false;
                f2 = arr[tmp * 2] < arr[tmp * 2 + 1] ? true : false;
            }
        }
        if(f1) swap(arr[tmp], arr[tmp * 2 + 1]), tmp = tmp * 2 + 1;
        if(f2) swap(arr[tmp], arr[tmp * 2]), tmp = tmp * 2;
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
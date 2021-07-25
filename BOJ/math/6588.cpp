#include <iostream>
#include <cmath>
#define MAX 1000001
using namespace std;

bool arr[MAX] = {false, };

void find_num(int num){
    for(int i = num; i > 2; i--){
        if(arr[i]) continue;
        if(!arr[num - i]) {
            cout << num << " = " << num - i << " + " << i << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

void chk_prime(){
    for(int i = 2; i <= sqrt(MAX); i++){
        if(arr[i]) continue;
        if(i % 2 == 0) arr[i] = true;
        for(int j = i * 2; j < MAX; j += i){
            if(arr[j]) continue;
            arr[j] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    arr[0] = arr[1] = true;
    chk_prime();

    int num;
    cin >> num;
    while(num){
        find_num(num);        
        cin >> num;
    }
}
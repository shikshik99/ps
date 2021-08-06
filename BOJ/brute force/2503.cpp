#include <iostream>
#include <cstring>
using namespace std;

bool chk[10][10][10];
int arr[10][10][10][2];
int N;

int main(){
    memset(chk, true, sizeof(chk));

    cin >> N;
    int num, strike, ball;
    int a, b, c;
    bool x, y, z;
    while(N--){
        memset(arr, 0, sizeof(arr));
        cin >> num >> strike >> ball;
        c = num % 10, num /= 10, b = num % 10, num /= 10, a = num;
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                for(int k = 1; k < 10; k++){
                    if(!chk[i][j][k]) continue;
                    if(i == j || i == k || j == k) {chk[i][j][k] = false; continue;}
                    x = false, y = false, z = false;

                    if(i == a) arr[i][j][k][0]++, x = true;
                    if(j == b) arr[i][j][k][0]++, y = true;
                    if(k == c) arr[i][j][k][0]++, z = true;
                    if(!x && i == b || i == c) arr[i][j][k][1]++;
                    if(!y && j == a || j == c) arr[i][j][k][1]++;
                    if(!z && k == a || k == b) arr[i][j][k][1]++;

                    if(arr[i][j][k][0] != strike || arr[i][j][k][1] != ball) chk[i][j][k] = false;
                }
            }
        }
    }   

    int answer = 0 ;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            for(int k = 1; k < 10; k++){
                if(!chk[i][j][k]) continue;
                answer++;
            }
        }
    }

    cout << answer << '\n';
}
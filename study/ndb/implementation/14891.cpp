#include <iostream>
#include <string>
using namespace std;

string s[4];
bool chkr[4];
bool chkl[4];

void rot(int a, int b){
    if(b == 1){
        auto tmp = s[a][7];
        for(int i = 6 ; i >= 0; i--){
            s[a][i + 1] = s[a][i];
        }
        s[a][0] = tmp;
    }
    else if (b == -1){
            auto tmp = s[a][0];
            for(int i = 1 ; i < 8; i++){
            s[a][i - 1] = s[a][i];
        }
        s[a][7] = tmp;
    }
}

void chk(int num){
    for(int j = num; j < 3; j++){
            if(s[j][2]==s[j+1][6]) break;
            else chkr[j+1] = true;
        }
    for(int j = num; j > 0; j--){
        if(s[j][6]==s[j-1][2]) break;
        else chkl[j-1] = true;
    }
}

int main(){
    int K, num, dir, ans = 0, dirr;

    for(int i = 0 ; i < 4; i++) cin >> s[i];

    cin >> K; 
    for(int i = 0; i < K; i++){
        fill_n(chkr, 4, false);
        fill_n(chkl, 4, false);
        cin >> num >> dir;
        num -= 1;
        chk(num);
        rot(num, dir);
        dirr = -dir;
        for(int j = num + 1; j <= 3; j++){
            if(!chkr[j]) break;
            else{rot(j,dirr);
            dirr *= -1;}
        }
        dirr = -dir;
        for(int j = num - 1; j >= 0; j--){
            if(!chkl[j]) break;
            else{rot(j,dirr);
            dirr *= -1;}
        }
    }
    if(s[0][0] == '1') ans +=1;
    if(s[1][0] == '1') ans +=2;
    if(s[2][0] == '1') ans +=4;
    if(s[3][0] == '1') ans +=8;
    cout<<ans;
}
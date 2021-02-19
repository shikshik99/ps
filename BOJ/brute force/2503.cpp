#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

vector <string> v;
bool chk[3];

int main(){
    int N, strike, ball, answer = 0;
    int cnt1, cnt2;
    string num;
    char a, b, c;
    cin >> N;
    for(int i = 111; i < 1000; i++) v.push_back(to_string(i));
    for(int i = 0; i < N; i++) {
        cin >> num >> strike >> ball;
        a = num[0], b = num[1], c = num[2];
        for(int j = 0; j < v.size(); j++){
            if(v[j] == "0") continue;
            if(v[j][0] == '0' || v[j][1] == '0' || v[j][2] == '0'){v[j] = "0"; continue;}
            if((v[j][0] == v[j][1]) || (v[j][0] == v[j][2]) || (v[j][1] == v[j][2])) {v[j] = "0"; continue;}
            memset(chk, false, sizeof(chk));
            cnt1 = 0, cnt2 = 0;
            if(v[j][0] == a) cnt1++, chk[0] = true;
            if(v[j][1] == b) cnt1++, chk[1] = true;
            if(v[j][2] == c) cnt1++, chk[2] = true;
            if(!chk[0] && (v[j][1] == a || v[j][2] == a)) cnt2++;
            if(!chk[1] && (v[j][0] == b || v[j][2] == b)) cnt2++;
            if(!chk[2] && (v[j][0] == c || v[j][1] == c)) cnt2++;
            if(strike != cnt1 || ball != cnt2) v[j] = "0";
        }
    }
    for(auto it : v) if(it != "0") answer++;
    cout << answer; 
}
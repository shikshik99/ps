#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A, B, tmp1, tmp2, ans;
vector <int> a, b;
vector <string> answer;

int main(){
    cin >> A >> B;
    int flag = 0, time = 0;
    for(int i = 0; i < A.length(); i++){
        if(A[i] == ':') a.push_back(stoi(tmp1)), b.push_back(stoi(tmp2)), tmp1.clear(), tmp2.clear();
        else if(i == A.length() - 1) tmp1 += A[i], tmp2 += B[i], a.push_back(stoi(tmp1)), b.push_back(stoi(tmp2));
        else tmp1 += A[i], tmp2 += B[i];
    }
    for(int i = 2; i >= 0; i--){
        time = b[i] - a[i] - flag, flag = 0;
        if(i){
            if(time < 0) time += 60, flag = 1;
        }
        else {
            if(time < 0) time += 24, flag = 1;
        }
        if(time < 10) answer.push_back("0" + to_string(time));
        else answer.push_back(to_string(time));
    }
    ans += answer[2];
    for(int i = 1; i >= 0; i--) ans += ':' + answer[i];
    if(ans == "00:00:00") cout << "24:00:00";
    else cout << ans;
}
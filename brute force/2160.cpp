#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <vector<string>>v;
string str;
int N, cnt = 0, ans1, ans2, tmp = 0;
bool flag = false;

void foo(){
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            cnt = 0;
            for(int k = 0; k < 5; k++){
                int idx = 0;
                while(idx < 7){
                    if(v[i][k].at(idx) != v[j][k].at(idx)) cnt++;
                    idx++;
                }
            }
            if(!flag) {flag = true; tmp = cnt; ans1 = i; ans2 = j;}
            if(flag && cnt < tmp) {tmp = cnt; ans1 = i; ans2 = j;} 
        }
    }
}

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            cin >> str;
            v[i].push_back(str);
        }
    }
    foo();
    cout << ans1+1 << ' ' << ans2+1;
}
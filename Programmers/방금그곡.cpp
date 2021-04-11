#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define psi pair<int, string>

vector <psi> v;

string foo1(string str){
    string tmp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '#') tmp[tmp.length() - 1] = tmp[tmp.length() - 1] + 32;
        else tmp += str[i];
    }
    return tmp;
}

bool foo(string m, string str, int min){
    string tmp;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        cnt = i + 1;
        if(str[i] == m[0]){
            int idx = i;
            while(tmp.size() < m.size() && cnt <= min){
                tmp += str[idx];
                idx++, idx %= str.length(), cnt++;
            }
            if(tmp == m) return true;
            tmp.clear();
        }
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string tmp;
    int cnt = 0, ma = 0, ma_idx = 0x6f6f6f6f;
    m = foo1(m);
    for(int i = 0; i < musicinfos.size(); i++){
        string tim1, tim2;
        for(int j = 0; j < musicinfos[i].length(); j++){
            if(musicinfos[i][j] == ',') cnt++;
            if(cnt == 0 && musicinfos[i][j] != ',') tim1 += musicinfos[i][j];
            if(cnt == 1 && musicinfos[i][j] != ',') tim2 += musicinfos[i][j];
            if(cnt == 2 && musicinfos[i][j] != ',') answer += musicinfos[i][j];
            if(cnt == 3 && musicinfos[i][j] != ',') tmp += musicinfos[i][j];
        }
        tmp = foo1(tmp);
        int timm1 =  ((tim1[0] - '0') * 10 + ((tim1[1] - '0'))) * 60 +((tim1[3] - '0') * 10 + ((tim1[4] - '0')));
        int timm2 = ((tim2[0] - '0') * 10 + ((tim2[1] - '0'))) * 60 + ((tim2[3] - '0') * 10 + ((tim2[4] - '0')));
        
        if(foo(m, tmp, timm2 - timm1)) {
            v.push_back({timm2 - timm1, answer});
            if(timm2 - timm1 > ma) ma = timm2 - timm1, ma_idx = v.size() - 1;
        }
        cnt = 0;
        answer.clear(), tmp.clear(), tim1.clear(), tim2.clear();
    }
    if(v.empty()) return "(None)";
    return v[ma_idx].second;
}
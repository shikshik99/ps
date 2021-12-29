#include <bits/stdc++.h>
using namespace std;

map <string, int> m;

bool solution(vector<string> p) {
    int len = p.size();
    for(int i = 0; i < len; i++) m[p[i]]++;
    for(int i = 0; i < len; i++){
        string str = "";
        for(int j = 0; j < p[i].length(); j++){
            str += p[i][j];
            if(j == p[i].length() - 1) break;
            if(m.count(str)) return false;
        }
    }
    
    return true;
}
#include <bits/stdc++.h>
using namespace std;

map <string, int> m1, m2;

string solution(vector<string> p, vector<string> c) {
    int len = p.size();
    for(int i = 0; i < len; i++){
        m1[p[i]]++;
    }
    
    len = c.size();
    for(int i = 0; i < len; i++){
        m2[c[i]]++;
    }
    
    for(auto it : m1){
        string ret = it.first;
        if(m1[ret] != m2[ret]) return ret;
    }
}
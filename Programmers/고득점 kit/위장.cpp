#include <bits/stdc++.h>
using namespace std;

map <string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    int len = clothes.size();
    for(int i = 0; i < len; i++){
        m[clothes[i][1]]++;
    }
    
    for(auto it : m){
        answer *= it.second + 1;
    }
    return answer - 1;
}
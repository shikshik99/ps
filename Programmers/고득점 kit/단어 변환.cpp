#include <bits/stdc++.h>
#define MAX 0x6f6f6f6f
using namespace std;

bool chk[51];
vector <string> v;
int N, len;

int DFS(string str, string target, int depth){
    if(str == target) return depth;
    int ret = MAX;
    
    for(int i = 0; i < N; i++){
        if(chk[i]) continue;
        int cnt = 0;
        for(int j = 0; j < len; j++){
            if(str[j] != v[i][j]) cnt++;
        }
        if(cnt >= 2) continue;
        
        chk[i] = true;
        ret = min(ret, DFS(v[i], target, depth + 1));
        chk[i] = false;
    }
    
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    v = words;
    N = words.size();
    len = words[0].length();
    int answer = DFS(begin, target, 0);
    
    if(answer == MAX) return 0;
    return answer;
}
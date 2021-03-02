#include <string>
using namespace std;

string solution(string s) {
    int i = 0, cnt = 0;
    while(i < s.length()){
        if(s[i] == ' ') {cnt = 0; i++; continue;}
        if(!(cnt % 2)) if(s[i] >= 97 && s[i] <= 97 + 26) s[i] -= 32;
        if(cnt % 2) if(s[i] >= 65 && s[i] <= 65 + 26) s[i] += 32;
        i++, cnt++;        
    }
    return s;
}
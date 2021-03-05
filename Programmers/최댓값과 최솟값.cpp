#include <string>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "", tmp = "";
    int ma = -999999999, mi = 0x7f7f7f7f;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            mi = min(stoi(tmp), mi), ma = max(stoi(tmp), ma), tmp.clear();
        }
        else tmp += s[i];
    }
    mi = min(stoi(tmp), mi), ma = max(stoi(tmp), ma), tmp.clear();
    answer = to_string(mi) + ' ' + to_string(ma);
    return answer;
}
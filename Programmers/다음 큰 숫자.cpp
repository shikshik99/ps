#include <bitset>
#include <string>
using namespace std;

int solution(int n) {
    int answer = n, cnt = 0;
    string str;
    str = bitset<32>(n).to_string();
    for(int i = 0; i < str.length(); i++) if(str[i] == '1') cnt++;
    int a = 0;
    while(a != cnt){
        answer++;
        a = 0;
        str = bitset<32>(answer).to_string();
        for(int i = 0; i < str.length(); i++) if(str[i] == '1') a++;
    }
    return answer;
}
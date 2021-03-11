#include <string>
#include <stack>
using namespace std;

stack <char>st;

bool solution(string s)
{
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')' && !st.empty()) st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) return true;
    else return false;
}
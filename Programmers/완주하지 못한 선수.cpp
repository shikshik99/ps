#include <string>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map <string,int>m;
    for(int i = 0; i < participant.size(); i++) m[participant[i]]++;
    for(int i = 0; i < completion.size(); i++) m[completion[i]]--;
    for(auto it : m){
        if(it.second > 0) return it.first;
    }
}
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;
map <string, int>m;
string str;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i = 0; i < clothes.size(); i++){
        str = clothes[i][1];
        if(m.count(str)) m[str]++;
        else m.insert(make_pair(str, 1));
    }
    for(auto it = m.begin(); it != m.end(); it++){
        answer *= it->second + 1;
    }
    
    return answer - 1;
}
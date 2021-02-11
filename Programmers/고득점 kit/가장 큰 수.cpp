#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <pair<int,int>> v;

string solution(vector<int> numbers) {
    string answer = "";
    string tmp = "";
    int j = 0;
    int len = numbers.size();
    int s;
    bool flag = false;
    for(int i = 0; i < len; i++){
        if(numbers[i] != 0) flag = true;
        tmp = to_string(numbers[i]), j = 0, s = tmp.size();
        while(tmp.size() < 4) tmp += tmp[j%s], j++;
        v.push_back({stoi(tmp), i});
    }
    if(!flag) return "0";
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i >= 0; i--) answer += to_string(numbers[v[i].second]);
    return answer;
}
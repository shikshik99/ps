#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0, tmp = 0;
    sort(citations.begin(), citations.end());
    while(answer < 10000){
        tmp = 0;
        for(int i = 0; i < citations.size(); i++) if(citations[i] >= answer) tmp++;
        if(tmp >= answer) answer++;
        else return answer-1;
    }
}
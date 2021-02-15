#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer, rank;
    vector <vector<int>> tmp;
    int ma = 0, a;
    tmp.resize(3);
    tmp[0] = {1,2,3,4,5};
    tmp[1] = {2,1,2,3,2,4,2,5};
    tmp[2] = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0 ; i < 3; i++){
        a = 0;
        for(int j = 0; j < answers.size(); j++){
            if(tmp[i][j%tmp[i].size()] == answers[j]) a++;
        }
        rank.push_back(a), ma = max(ma, a);
    }
    for(int i = 0; i < 3; i++){
        if(rank[i] == ma) answer.push_back(i+1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
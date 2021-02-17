#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0, i;
    vector <int>v(n);
    for(i = 0; i < lost.size(); i++) v[lost[i] - 1]--;
    for(i = 0; i < reserve.size(); i++) v[reserve[i] - 1]++;
    for(i = 0; i < v.size(); i++){
        if(v[i] == -1){
            if(i != v.size() - 1 && v[i+1] == 1) v[i+1]--, v[i]++;
            else if(i != 0 && v[i-1] == 1) v[i-1]--, v[i]++;
        }
    }
    for(auto it : v) if(it != -1) answer++;
    return answer;
}
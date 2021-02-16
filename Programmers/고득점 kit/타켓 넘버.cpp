#include <string>
#include <vector>
using namespace std;

int dfs(int start, vector<int> &num, int target, int tmp){
    int answer = 0;
    if(start >= num.size()) return 0;
    
    answer += dfs(start + 1, num, target, tmp + num[start]);
    answer += dfs(start + 1, num, target, tmp - num[start]);
    
    if(start == num.size() - 1 && tmp + num[start] == target) answer++;
    if(start == num.size() - 1 && tmp - num[start] == target) answer++;
    return answer;
}

int solution(vector<int> numbers, int target) {
    return dfs(0, numbers, target, 0);
}
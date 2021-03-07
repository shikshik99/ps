#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector <int> v;
    for(auto it : arr){
        if(v.empty()) v.push_back(it);
        else if(v[v.size() - 1] == it) continue;
        else v.push_back(it);
    }
    return v;
}
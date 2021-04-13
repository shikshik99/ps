#include <string>
#include <vector>
using namespace std;

string foo(int tmp, int size){
    string str;
    str.resize(size, ' ');
    int idx = size - 1;
    while(tmp && idx >= 0){
        if(tmp % 2) str[idx] = '#';
        tmp/=2, idx--;
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp1, tmp2;
    for(int i = 0; i < n; i++){
        tmp1 = foo(arr1[i], n), tmp2 = foo(arr2[i], n);
        for(int j = 0; j < n; j++){
            if(tmp1[j] == '#' || tmp2[j] == '#') tmp1[j] = '#';
        }
        answer.push_back(tmp1);
    }
    return answer;
}
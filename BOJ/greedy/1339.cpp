#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

map <char, int> m;
vector <string> v;
vector <char> tmp;
int N;

int calc(){
    int ret = 0, temp = 0;
    for(int i = 0; i < N; i++){
        temp = 0;
        for(int j = 0; j < v[i].length(); j++){
            temp = (temp * 10) + m[v[i][j]];
        }
        ret += temp;
    }

    return ret;
}

int main(){
    for(int i = 0; i < 26; i++) m[i + 'A'] = 0;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str, v.push_back(str);
        for(int j = 0; j < str.length(); j++){
            tmp.push_back(str[j]);
        }
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    int answer = 0;
    do{
        int cnt = 9;
        for(int i = 0; i < tmp.size(); i++){
            m[tmp[i]] = cnt;
            cnt--;
        }
        answer = max(answer, calc());
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << answer << '\n';
}
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map <string, int>m;
vector <string>v;

int main(){
    int N, answer = 0;
    string str;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> str, m[str] = i;
    for(int i = 0; i < N; i++) cin >> str, v.push_back(str);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(m[v[i]] > m[v[j]]){
                answer++; break;
            }
        }
    }
    cout << answer;
}
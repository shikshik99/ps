#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map <string, int>m;
map <int, string>m2;
vector <string> answer;
int N, M;

int main(){
    string question;
    cin >> N >> M;
    answer.resize(M);
    for(int i = 0; i < N; i++) cin >> question, m[question] = i + 1, m2[i+1] = question;
    question.clear();
    for(int i = 0; i < M; i++){
        cin >> question;
        if(question[0] >= 65 && question[0] <= 65 + 26) answer[i] = to_string(m[question]);
        else answer[i] = m2[stoi(question)];
    }
    for(auto it : answer) cout << it << '\n';
}
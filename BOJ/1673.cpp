#include <iostream>
#include <vector>
using namespace std;

vector <int> answer;

int main(){
    int N, K, tmp;
    cin >> N >> K;
    while(!cin.eof()){
        tmp = N;
        while(N >= K) tmp += N/K, N = N/K + N%K;
        answer.push_back(tmp);
        cin >> N >> K;
    }
    for(auto it : answer) cout << it << '\n';
}
#include <iostream>
#include <vector>
using namespace std;

vector <int>answer;

int main(){
    int L, P , V, cnt;
    cin >> L >> P >> V;
    while(L && P && V){
        cnt = (V/P)*L, V%=P;
        if(V >= L) cnt += L;
        else cnt += V;
        answer.push_back(cnt);
        cin >> L >> P >> V;
    }
    int i = 1;
    for(auto it : answer) cout << "Case " << i << ": " << it << '\n', i++;
}
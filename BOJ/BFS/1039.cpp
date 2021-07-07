#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define psi pair<string, int>

int K;
bool chk[1000001][11];
string N;

int BFS(){
    memset(chk, false, sizeof(chk));
    queue <psi>q;
    q.push({N, 0});

    int answer = -1;
    while(!q.empty()){
        string tmp = q.front().first;
        int cnt = q.front().second + 1; 
        q.pop();
        if(cnt > K) {
            answer = max(answer, stoi(tmp));
            continue;
        }

        for(int i = 0; i < tmp.length(); i++){
            for(int j = i + 1; j < tmp.length(); j++){
                string str = tmp;
                swap(str[i], str[j]);
                if(str[0] == '0' || chk[stoi(str)][cnt]) continue;
                chk[stoi(str)][cnt] = true;
                q.push({str, cnt});
            }
        }
    }

    return answer;
}

int main(){
    cin >> N >> K;

    cout << BFS();
}
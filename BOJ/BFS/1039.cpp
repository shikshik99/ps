#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using psi = pair<string, int>;

bool chk[1000001][11];
string str;
int K;

string SWAP(string tmp, int i, int j){
    swap(tmp[i], tmp[j]);
    return tmp;
}

int BFS(){
    int answer = -1;
    memset(chk, false, sizeof(chk));
    queue <psi> q;
    q.push({str, 0});
    chk[stoi(str)][0] = true;

    while(!q.empty()){
        string tmp = q.front().first, swp;
        int cnt = q.front().second + 1;
        q.pop();
        for(int i = 0; i < tmp.length(); i++){
            for(int j = i + 1; j < tmp.length(); j++){
                swp = SWAP(tmp, i, j);
                if(swp[0] == '0' || chk[stoi(swp)][cnt]) continue;
                if(cnt == K) answer = max(answer, stoi(swp));
                else{
                    chk[stoi(swp)][cnt] = true;
                    q.push({swp, cnt});
                }
            }
        }
    }

    return answer;
}

int main(){
    cin >> str >> K;
    cout << BFS();
}
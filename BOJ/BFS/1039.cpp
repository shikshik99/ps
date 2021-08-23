#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 1000001
using namespace std;

bool chk[MAX][11] = {false, };
int K;
string N;

int BFS(){
    queue <string> q;
    q.push(N);
    chk[stoi(N)][0] = true;
    
    int ret = -1;
    int len = N.length();
    int cnt = 0;
    while(!q.empty() && cnt < K){
        int qsize = q.size();
        cnt++;
        while(qsize--){
            string str = q.front();
            q.pop();
            for(int i = 0; i < len; i++){
                for(int j = i + 1; j < len; j++){
                    string next = str;
                    swap(next[i], next[j]);
                    int num = stoi(next);
                    if(chk[num][cnt] || next[0] == '0') continue;
                    if(cnt == K) ret = max(ret, num);
                    chk[num][cnt] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return ret;
}

int main(){
    cin >> N >> K;
    cout << BFS() << '\n';
}
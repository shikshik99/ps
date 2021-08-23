#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

set <string> s;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mov[4] = {-3, 3, -1, 1};
string str, ans;

int BFS(){
    queue <string> q;
    q.push(str);
    s.insert(str);

    int ret = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            string tmp = q.front();
            if(tmp == ans) return ret;
            q.pop();
            int position;
            for(int i = 0; i < 9; i++){
                if(tmp[i] == '0') position = i;
            }
            int x = position / 3;
            int y = position % 3;
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= 3 || dy < 0 || dy >= 3) continue;
                int pos = position + mov[i];
                string next = tmp;
                swap(next[pos], next[position]);
                if(s.find(next) == s.end()) s.insert(next), q.push(next);
            }
        }
        ret++;
    }

    return -1;
}

int main(){
    int num;
    ans = "123456780";
    for(int i = 0; i < 9; i++){
        cin >> num;
        str += (num + '0');
    }

    cout << BFS() << '\n';
}

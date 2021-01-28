#include <iostream>
#include <queue>
using namespace std;

queue <pair<int,int>>q;
priority_queue <int>pq;

pair <int,int> tmp;

int main(){
    int T, a, b, c, cnt=1;
    cin>>T;
    for(int i = 0 ; i<T; i++){
        cin >> a >> b;
        for(int j = 0 ; j < a; j++){
            cin>>c;
            q.push(make_pair(j,c));
            pq.push(c);
        }
        while(1){
            if(q.front().second != pq.top()){
                tmp.first = q.front().first;
                tmp.second = q.front().second;
                q.pop();
                q.push(tmp);
            }
            else {
                if(b == q.front().first) {cout << cnt <<'\n'; break;}
                q.pop();
                pq.pop();
                cnt++;
            }
        }
        cnt=1;
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
    }
}
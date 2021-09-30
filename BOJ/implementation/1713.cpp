#include <bits/stdc++.h>
#define INF 0x6f6f6f6f
using namespace std;

struct info{
    bool is_in = false;
    int cnt = 0;
    int du = 0;
};

int frame[21];
info stu[101];
int N, M;

int main(){
    cin >> N >> M;
    memset(frame, -1, sizeof(frame));
    
    int num;
    while(M--){
        cin >> num;

        stu[num].cnt++;
        if(stu[num].is_in) continue;
        stu[num].du = M;

        int minidx = 0;
        int cnt = INF, du = 0;

        for(int i = 0; i < N; i++){
            if(frame[i] == -1){
                stu[num].is_in = true;
                frame[i] = num;
                break;
            }
            
            int tmp = frame[i];
            if(!stu[tmp].is_in) continue;
            
            if(stu[tmp].cnt < cnt){
                minidx = i;
                cnt = stu[tmp].cnt;
                du = stu[tmp].du;
            }
            if(stu[tmp].cnt == cnt){
                if(stu[tmp].du < du) continue;
                minidx = i;
                cnt = stu[tmp].cnt;
                du = stu[tmp].du;
            }
        }

        if(stu[num].is_in) continue;
        stu[num].is_in = true;

        int minnum = frame[minidx];
        frame[minidx] = num;
        stu[minnum].is_in = false;
        stu[minnum].cnt = 0;
        stu[minnum].du = 0;
    }
    
    sort(frame, frame + N);
    for(int i = 0; i < N; i++){
        if(frame[i] == -1) continue;
        cout << frame[i] << ' ';
    }
}

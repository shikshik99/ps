#include <bits/stdc++.h>
#define MAX 51
#define INF 0x6f6f6f6f
using namespace std;
using pii = pair<int, int>;

int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool chk[MAX][MAX];
int board[MAX][MAX];
bool combi[11];
vector <pii> virus;
int N, M;
int answer = INF, cnt;

int BFS(){
    int ret = 0;
    int tmp = cnt;
    memset(chk, false, sizeof(chk));
    queue <pii> q;

    int x, y;
    for(int i = 0; i < virus.size(); i++){
        if(!combi[i]) continue;
        x = virus[i].first;
        y = virus[i].second;
        q.push({x, y});
        chk[x][y] = true;
    }

    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + arr[i][0];
                int dy = y + arr[i][1];
                if(dx < 0 || dx >= N || dy < 0 || dy >= N || chk[dx][dy] || board[dx][dy] == 1) continue;
                chk[dx][dy] = true;
                q.push({dx, dy});
                if(!board[dx][dy]) tmp--;
            }
        }
        ret++;
        if(!tmp) return ret;    
    }
    
    return INF;
}

void combination(int idx, int depth){
    if(depth == M){
        answer = min(answer, BFS());
        return ;
    }
    
    for(int i = idx; i < virus.size(); i++){
        combi[i] = true;
        combination(i + 1, depth + 1);
        combi[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i, j});
            if(!board[i][j]) cnt++;
        }
    }
    if(!cnt) {
        cout << 0 << '\n';
        return 0;
    }
    combination(0, 0);
    cout << (answer == INF ? -1 : answer) << '\n';
}
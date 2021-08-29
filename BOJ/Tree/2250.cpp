#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
#define INF 0x6f6f6f6f
using namespace std;

int arr[MAX], ma[MAX], mi[MAX], cnt[MAX];
int N, max_depth = 0;
vector <vector<int>> v;

void DFS(int idx, int depth){
    max_depth = max(max_depth, depth);
    int left = v[idx][0], right = v[idx][1];
    
    ma[depth] = max(ma[depth], arr[idx]);
    mi[depth] = min(mi[depth], arr[idx]);
    if(left != -1) DFS(left, depth + 1);
    if(right != -1) DFS(right, depth + 1);
}

int find_pos(int idx, int cnt){
    int left = v[idx][0], right = v[idx][1];

    int pos = cnt + 1;
    if(left != -1) pos = find_pos(left, cnt) + 1;
    arr[idx] = pos;
    if(right != -1) pos = find_pos(right, pos);

    return pos;
}

int main(){
    fill(ma, ma + MAX, 0);
    fill(mi, mi + MAX, INF);
    cin >> N;
    v.resize(N + 1);
    int curr, left, right;
    for(int i = 0; i < N; i++){
        cin >> curr >> left >> right;
        if(left != -1) cnt[left]++;
        if(right != -1) cnt[right]++;
        v[curr].push_back(left);
        v[curr].push_back(right);
    }

    int root = 1;
    for(int i = 1; i <= N; i++){
        if(!cnt[i]) root = i;
    }

    find_pos(root, 0);
    DFS(root, 1);

    pair <int, int> answer = {1, 0};
    for(int i = 1; i <= max_depth; i++) {
        if(answer.second < ma[i] - mi[i]) answer.first = i, answer.second = ma[i] - mi[i];
    }

    cout << answer.first << ' ' << answer.second + 1 << '\n';
}
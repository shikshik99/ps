#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector <pii> player;
vector <int> tree;
int N;

bool cmp_index(pii a, pii b){
    return a.first < b.first ? true : false;
}

bool cmp_rank(pii a, pii b){
    return a.second < b.second ? true : false;
}

void update(int start, int end, int node, int idx){
    if(idx < start || idx > end) return;
    tree[node]++;
    if(start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx);
    update(mid + 1, end, node * 2 + 1, idx);
}

int Q(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    
    return Q(start, mid, node * 2, left, right) + Q(mid + 1, end, node * 2 + 1, left, right);
}

int main(){
    cin >> N;
    player.resize(N);
    tree.resize(4 * N, 0);

    for(int i = 0; i < N; i++) cin >> player[i].second, player[i].first = i;

    sort(player.begin(), player.end(), cmp_rank);
    for(int i = 0; i < N; i++) player[i].second = i;

    sort(player.begin(), player.end(), cmp_index);
    
    for(int i = 0; i < N; i++){
        int rank = Q(0, N - 1, 1, 0, player[i].second);
        cout << i - rank + 1 << '\n';
        update(0, N - 1, 1, player[i].second);
    }
}
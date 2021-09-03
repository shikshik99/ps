#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector <pii> v;
vector <int> tree;
int N;

bool cmp(pii a, pii b){
    return a.second < b.second ? true : false;
}

int Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return max(Query(start, mid, node * 2, left, right), Query(mid + 1, end, node * 2 + 1, left, right));
}

int update(int start, int end, int node, int idx, int val){
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] = val;
    int mid = (start + end) / 2;
    return tree[node] = max(update(start, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    tree.resize(4 * N, 0);
    
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back({i, num});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < N; i++){
        int idx = v[i].first;
        int val = Query(0, N - 1, 1, 0, idx);
        update(0, N - 1, 1, idx, val + 1);
    }

    cout << N - tree[1] << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define INF 0x6f6f6f6f
using namespace std;

int arr[MAX];
vector <int> max_tree, min_tree;
int N, M;

int init_max(int start, int end, int node){
    if(start == end) return max_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return max_tree[node] = max(init_max(start, mid, node * 2), init_max(mid + 1, end, node * 2 + 1));
}

int init_min(int start, int end, int node){
    if(start == end) return min_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return min_tree[node] = min(init_min(start, mid, node * 2), init_min(mid + 1, end, node * 2 + 1));
}

int max_Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return max_tree[node];
    int mid = (start + end) / 2;
    return max(max_Query(start, mid, node * 2, left, right), max_Query(mid + 1, end, node * 2 + 1, left, right));
}

int min_Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return INF;
    if(left <= start && end <= right) return min_tree[node];
    int mid = (start + end) / 2;
    return min(min_Query(start, mid, node * 2, left, right), min_Query(mid + 1, end, node * 2 + 1, left, right));
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    max_tree.resize(4 * N, 0);
    min_tree.resize(4 * N, 0);
    init_max(0, N - 1, 1);
    init_min(0, N - 1, 1);
    int a, b;
    while(M--){
        cin >> a >> b;
        a--, b--;
        cout << min_Query(0, N - 1, 1, a, b) << ' ' << max_Query(0, N - 1, 1, a, b) << '\n';
    }
}
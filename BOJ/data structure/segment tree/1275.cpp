#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
using ll = long long;

int arr[MAX];
vector <ll> tree;
int N, Q;

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return Query(start, mid, node * 2, left, right) + Query(mid + 1, end, node * 2 + 1, left, right); 
}

ll update(int start, int end, int node, int idx, int num){
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] = num;
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, idx, num) + update(mid + 1, end, node * 2 + 1, idx, num);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;

    for(int i = 0; i < N; i++) cin >> arr[i];
    tree.resize(N * 4, 0);
    init(0, N - 1, 1);

    int x, y, a, b;
    while(Q--){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << Query(0, N - 1, 1, x - 1, y - 1) << '\n';
        update(0, N - 1, 1, a - 1, b);
    }
}
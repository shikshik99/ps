#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
using ll = long long;

ll arr[MAX];
vector <ll> tree;
int N, Q;

void update(int start, int end, int node, int idx, ll dif){
    if(idx < start || idx > end) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, dif); 
    update(mid + 1, end, node * 2 + 1, idx, dif);
}

ll query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> arr[i];

    tree.resize(4 * N, 0);

    ll x, y, a, b;
    init(0, N - 1, 1);
    while(Q--){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << query(0, N - 1, 1, x - 1, y - 1) << '\n'; 
        ll dif = (b - arr[a - 1]);
        arr[a - 1] = b;
        update(0, N - 1, 1, a - 1, dif);
    }
}
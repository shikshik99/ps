#include <iostream>
#include <vector>
#define MAX 1000001
#define MOD 1000000007
using namespace std;
using ll = long long;

int arr[MAX];
int N, M, K;
vector <ll> tree;

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = ((init(start, mid, node * 2) % MOD) * (init(mid + 1, end, node * 2 + 1) % MOD))% MOD;
}

ll update(int start, int end, int node, int index, ll dif){
    if(index < start || index > end) return tree[node];  
    if(start == end) return tree[node] = dif % MOD;
    int mid = (start + end) / 2;
    return tree[node] = ((update(start, mid, node * 2, index, dif) % MOD) * (update(mid + 1, end, node * 2 + 1, index, dif) % MOD)) % MOD;
}

ll Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return ((Query(start, mid, node * 2, left, right) % MOD) * (Query(mid + 1, end, node * 2 + 1, left, right) % MOD)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    tree.resize(N * 4, 0);
    
    for(int i = 0; i < N; i++) cin >> arr[i];
    init(0, N - 1, 1);

    int a, b, c;
    M += K;
    while(M--){
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            arr[b] = c;
            update(0, N - 1, 1, b, c);
        }
        else{
            b--, c--;
            cout << Query(0, N - 1, 1, b, c) << '\n';
        }
    }
}
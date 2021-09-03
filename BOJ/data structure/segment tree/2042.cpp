#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;
using ll = long long;

ll arr[MAX];
int N, M, K;
vector <ll> tree;

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left , right);
}

void update(int start, int end, int node, int index, ll dif){
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    M += K;

    tree.resize(N * 4, 0);
    init(0, N - 1, 1);
    ll a, b, c;
    while(M--){
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            ll dif = (c - arr[b]);
            arr[b] = c;
            update(0, N - 1, 1, b, dif);
        }
        else{
            b--, c--;
            cout << sum(0, N - 1, 1, b, c) << '\n';
        }
    }
}
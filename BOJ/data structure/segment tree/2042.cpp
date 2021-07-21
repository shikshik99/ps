#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
using ll = long long;

ll arr[MAX + 1];
vector <ll> tree;
int N, M, K;

void update(int start, int end, int node, int index, ll dif){
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int main(){
    cin >> N >> M >> K;
    tree.resize(4 * N, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];

    init(0, N - 1, 1);

    int tmp = M + K;
    ll a, b, c;
    while(tmp--){
        cin >> a >> b >> c;
        if(a == 1){
            ll dif = (c - arr[b - 1]);
            arr[b - 1] = c;
            update(0, N - 1, 1, b - 1, dif);
        }
        else if(a == 2){
            cout << sum(0, N - 1, 1, b - 1, c - 1) << '\n';
        }
    }
}
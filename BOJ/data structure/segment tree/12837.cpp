#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;
using ll = long long;

vector <ll> tree;
int N, Q;

ll update(int start, int end, int node, int idx, ll dif){
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] += dif;
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, idx, dif) + update(mid + 1, end, node * 2 + 1, idx, dif);
}

ll Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return Query(start, mid, node * 2, left, right) + Query(mid + 1, end, node * 2 + 1, left, right);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    tree.resize(4 * N, 0);
    
    int a, b, c;
    while(Q--){
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            update(0, N - 1, 1, b, c);
        }
        else{
            b--, c--;
            cout << Query(0, N - 1, 1, b, c) << '\n';
        }
    }
}
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

bool chk[MAX] = {false, };
int pos[MAX] = {false, };
vector <int> tree;
int N;

int init(int start, int end, int node){
    if(start == end) return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int Query(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return Query(start, mid, node * 2, left, right) + Query(mid + 1, end, node * 2 + 1, left, right);
}

int update(int start, int end, int node, int idx, int val){
    if(idx < start || idx > end) return tree[node];
    if(start == end) return tree[node] = val;
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    tree.resize(4 * N, 0);

    int num;
    for(int i = 0; i < N; i++) cin >> num, pos[num] = i;
    init(0, N - 1, 1);

    int l = 1, r = N, cnt = 0;
    while(!chk[l] && !chk[r]){
        cnt++;
        if(cnt % 2){
            chk[l] = true;
            if(pos[l] - 1 >= 0) cout << Query(0, N - 1, 1, 0, pos[l] - 1) << '\n';
            else cout << 0 << '\n';
            update(0, N - 1, 1, pos[l], 0);
            l++;
        }
        else{
            chk[r] = true;
            if(pos[r] + 1 < N) cout << Query(0, N - 1, 1, pos[r] + 1, N - 1) << '\n';
            else cout << 0 << '\n';
            update(0, N - 1, 1, pos[r], 0);
            r--;
        }
    }

}
#include <iostream>
#define MAX 1000001
using namespace std;

int tree[MAX * 4] = {0, };

void update(int start, int end, int node, int index, int dif){
    if(index < start || index > end) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int Q(int start, int end, int node, int cnt){
    int ret;
    if(start == end) {
        cout << start << '\n';
        return start;
    }
    int mid = (start + end) / 2;
    if(tree[node * 2] >= cnt) {
        ret = Q(start, mid, node * 2, cnt);
    }
    else {
        ret = Q(mid + 1, end, node * 2 + 1, cnt - tree[node * 2]);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;

    int a, b, c;
    while(N--){
        cin >> a;
        if(a == 1) {
            cin >> b;
            int tmp = Q(1, MAX - 1, 1, b);
            update(1, MAX - 1, 1, tmp, - 1);
        }
        if(a == 2) {
            cin >> b >> c;
            update(1, MAX - 1, 1, b, c);
        }
    }
}
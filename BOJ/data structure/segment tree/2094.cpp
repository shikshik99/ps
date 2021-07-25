#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector <pii> info;
vector <int> tree;
int N;

bool cmp(pii a, pii b){
    return a.first < b.first ? true : false;
}

int Q(int start, int end, int node, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return max(Q(start, mid, node * 2, left, right), Q(mid + 1, end, node * 2 + 1, left, right));
}

int init(int start, int end, int node){
    if(start == end) return tree[node] = info[start].second;
    int mid = (start + end) / 2;
    return tree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int foo(int y, int x){
    pii tmp = {y, 0};
    int yidx = lower_bound(info.begin(), info.end(), tmp) - info.begin();
    tmp = {x, 0};
    int xidx = lower_bound(info.begin(), info.end(), tmp) - info.begin();
    
    bool a = false, b = false;
    // if(yidx == xidx) return -1;
    if(yidx < N && info[yidx].first == y) a = true;
    if(xidx < N && info[xidx].first == x) b = true;

    if(a && b && info[xidx].second > info[yidx].second) return 0;

    int left = yidx, right = xidx;
    if(a) left++;
    right--;
    int max_rain = Q(0, N - 1, 1, left, right);
    // cout << yidx << ' ' << xidx << '\n';
    // cout << "MAX_RAIN : " << max_rain << '\n';

    if(a && info[yidx].second <= max_rain) return 0;
    if(b && info[xidx].second <= max_rain) return 0;

    if(a && b){
        bool f = true;
        int year = y;
        for(int i = yidx; i <= xidx; i++){
            if(info[i].first != year) {
                f = false; break;
            }
            year++;
        }
        if(f) return 1;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    info.resize(N);
    tree.resize(4 * N, 0);

    for(int i = 0; i < N; i++) cin >> info[i].first >> info[i].second;
    sort(info.begin(), info.end(), cmp);
    init(0, N - 1, 1);

    int m;
    cin >> m;

    int y, x;
    while(m--){
        cin >> y >> x;
        int ans = foo(y, x);
        if(ans == -1) cout << "maybe\n";
        else if(!ans) cout << "false\n";
        else cout << "true\n";
    }
}
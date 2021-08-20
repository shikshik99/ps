#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator() (int a, int b){
        return a > b ? true : false;
    }
};

priority_queue <int> ma;
priority_queue <int, vector<int>, cmp> mi;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        if(ma.size() <= mi.size()) ma.push(x);
        else mi.push(x);
        if(!mi.empty() && ma.top() > mi.top()) {
            int tmp = ma.top(); ma.pop();
            ma.push(mi.top()), mi.pop();
            mi.push(tmp);
        }
        cout << ma.top() << '\n';
    }
}
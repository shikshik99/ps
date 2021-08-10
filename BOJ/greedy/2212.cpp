#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
vector <int> tmp;
int N, K;

bool cmp(int a, int b){
    return a > b ? true : false;
}

int main(){
    cin >> N >> K;
    K--;

    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int len = v.size();
    for(int i = 0; i < len - 1; i++) tmp.push_back(v[i + 1] - v[i]);
    sort(tmp.begin(), tmp.end(), cmp);

    int answer = v[len - 1] - v[0];
    len = tmp.size();
    for(int i = 0; i < len; i++){
        if(!K) break;
        answer -= tmp[i], K--;
    }

    cout << answer << '\n';
}
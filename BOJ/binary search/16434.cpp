#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <pair <int, pii>> v;
int N;

bool possible(ll mid, ll ATK){
    ll hp = mid;
    ll atk = ATK;
    for(int i = 0; i < N; i++){
        pii tmp = v[i].second;
        int num = v[i].first;

        if(num == 1){ // 몬스터
            int monster_atk = tmp.first;
            int monster_hp = tmp.second;
            ll dmg = ((monster_hp - 1) / atk) * monster_atk; // 딱 나눠 떨어지는 경우에는 떄리는 순간 죽기 때문에 -1 해줌(맞는 횟수가 1 줄어든다)
            if(hp - dmg <= 0) return false;
            hp -= dmg;
        }
        else{
            atk += tmp.first;
            hp += tmp.second;
            hp = hp < mid ? hp : mid;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll lo = 0, hi = 123456000000000000LL, mid, ATK;
    cin >> N >> ATK;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second.first >> v[i].second.second;

    while(lo + 1 < hi){
        mid = (lo + hi) / 2;
        if(possible(mid, ATK)) hi = mid;
        else lo = mid;
    }

    cout << hi << '\n';
}
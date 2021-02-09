#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define ll long long

ll arr[10] = {0};
ll tmp[10] = {0};
string str;
stack <char>s;
ll N, K, cnt = 0;

int main(){
    cin >> N >> K >> str;
    for(ll i = 0; i < str.size(); i++) arr[str[i]-'0']++;
    for(ll i = 0; i < 10; i++){
        cnt += arr[i];
        if(cnt > K) {
            cnt -= arr[i], tmp[i] = K - cnt; break;
        }
        else if(cnt == K) {tmp[i] = arr[i]; break;}
        else tmp[i] = arr[i];
    }
    for(ll i = 0; i < str.size(); i++) {
        if(tmp[str[i]-'0']) tmp[str[i]-'0']--;
        else s.push(str[i]);
    }
    str.clear();
    while(!s.empty()) str += s.top(), s.pop();
    for(ll i = str.size() - 1; i >= 0; i--) cout << str[i];
}
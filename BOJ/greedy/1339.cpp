#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

vector <ll> v;
int N;

void add_alpha(string str){
    for(int i = 0; i < str.length(); i++){
        int num = str.length() - i - 1;
        int tmp = 1;
        while(num--) tmp *= 10;
        v[str[i] - 'A'] += tmp;
    }
}

int main(){
    cin >> N;
    string str;

    v.resize(26, 0);
    for(int i = 0; i < N; i++){
        cin >> str;
        add_alpha(str);
    }
    sort(v.begin(), v.end(), greater<>());

    int i = 0, j = 9;
    ll answer = 0;
    while(v[i]){
        answer += (v[i] * j);
        i++, j--;
    }
    
    cout << answer << '\n';
}
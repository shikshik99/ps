#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string>v;

int main(){
    string str;
    int N;
    cin >> N, cin.ignore();
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(str[j] >= 'a') continue;
            str[j] += 32;
        }
        v.push_back(str);
    }
    for(auto it : v) cout << it << '\n';
}
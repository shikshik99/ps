#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> v, v2;

int main(){
    int N, K;
    string str, tmp;
    cin >> N >> K >> str;
    tmp.clear();
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ',') v.push_back(stoi(tmp)), tmp.clear();
        else if (i == str.length() - 1) tmp += str[i], v.push_back(stoi(tmp));
        else tmp += str[i];
    }
    while(K--){
        for(int i = 1; i < v.size(); i++) v2.push_back(v[i] - v[i-1]);
        v = v2, v2.clear();
    }
    for(int i = 0; i < v.size(); i++) {
        if(i == v.size() - 1) cout << v[i];
        else cout << v[i]<< ',';
    }
}
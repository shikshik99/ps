#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector <string>v;

int main(){
    int N;
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) cin >> str, v.push_back(str);
    str = v[0];
    for(int i = 1; i < N; i++){
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] == str[j]) str[j] = v[i][j];
            else str[j] = '?';
        }
    }
    cout << str;
}
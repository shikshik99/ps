#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector <string>ans;

int main(){
    int N, j;
    cin >> N;
    cin.ignore();
    ans.resize(N);
    for(int i = 0; i < N; i++){
        getline(cin, str);
        ans[i] += "god";
        j = 0;
        auto it = str.begin();
        while(*it != ' ')it++;
        str.erase(str.begin(), it);
        it = str.begin();
        while(it != str.end()) {if(*it == ' ') str.erase(it); it++;}
        ans[i] += str;
    }
    for(auto it : ans) cout << it << '\n';
}
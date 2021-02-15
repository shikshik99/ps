#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector <string> ans;

void foo(){
    string tmp, tmp1;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, tmp);
        tmp1 = "";
        for(int j = 0; j < tmp.length(); j++){
            if(tmp[j] >= 'A' && tmp[j] <= 'Z') tmp[j] = tmp[j]-'A'+'a';
        }
        for(int j = tmp.length()-1; j >= 0; j--) tmp1 += tmp[j];
        if(tmp == tmp1) ans.push_back("Yes");
        else ans.push_back("No");
    }
}

int main(){
    cin >> N;
    foo();
    for(auto it : ans) cout << it << '\n';
}
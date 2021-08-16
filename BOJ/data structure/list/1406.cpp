#include <iostream>
#include <list>
#include <string>
using namespace std;

list <char> l;

int main(){
    string str;
    int N;
    cin >> str >> N;
    for(auto it : str) l.push_back(it);
    auto it = l.end();

    char cmd, ch;
    while(N--){
        cin >> cmd;
        if(cmd == 'L'){
            if(it != l.begin()) it--;
        }
        if(cmd == 'D'){
            if(it != l.end()) it++;
        }
        if(cmd == 'B'){
            if(it != l.begin()){
                it--; it = l.erase(it);
            }
        }
        if(cmd == 'P'){
            cin >> ch;
            l.insert(it, ch);
        }
    }

    for(auto it : l) cout << it;
}
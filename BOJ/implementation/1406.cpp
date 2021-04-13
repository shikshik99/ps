#include <iostream>
#include <list>
#include <string>
using namespace std;

list <char>l;

int main(){
    string str;
    int N;
    char cmd, cha;
    cin >> str >> N;
    for( auto it : str) l.push_back(it);
    auto it = l.end();
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, str);
        if(str.length() > 1) cmd = str[0], cha = str[2];
        else cmd = str[0];
        if(cmd == 'L'){
            if(it == l.begin()) ;
            else it--;
        }
        else if(cmd == 'D'){
            if(it == l.end()) ;
            else it++;
        }
        else if(cmd == 'B'){
            if(it == l.begin()) ;
            else it--, it = l.erase(it);
        }
        else if(cmd == 'P'){
            if(it == l.end()) l.insert(it, cha), it = l.end();
            else l.insert(it, cha);
        }
    }
    for(auto it : l) cout << it;
}